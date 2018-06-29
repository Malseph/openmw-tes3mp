#include "DynamicRecords.hpp"
#include <apps/openmw-mp/Script/ScriptFunctions.hpp>
#include <components/openmw-mp/NetworkMessages.hpp>
#include <apps/openmw-mp/Networking.hpp>
#include <components/misc/stringops.hpp>

using namespace mwmp;

//region Generic Functions

void DynamicRecordFunctions::InitializeDynamicRecordChanges(unsigned short pid) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    player->dynamicRecordChanges.records.clear();
}

unsigned int DynamicRecordFunctions::GetDynamicRecordChangesSize(unsigned short pid) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    return player->dynamicRecordChanges.count;
}

unsigned int DynamicRecordFunctions::GetDynamicRecordChangesAction(unsigned short pid) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    return player->dynamicRecordChanges.action;
}

void DynamicRecordFunctions::SetDynamicRecordChangesAction(unsigned short pid, unsigned char action) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    player->dynamicRecordChanges.action = action;
}

void DynamicRecordFunctions::SetDynamicRecordRefId(unsigned short pid, unsigned int i, const char* refId) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    if (i >= player->dynamicRecordChanges.count)
        return;

    player->dynamicRecordChanges.records.at(i).refId = refId;
}

int DynamicRecordFunctions::AddDynamicRecord(unsigned short pid, const char* refId, int type) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    DynamicRecord record;
    record.refId = refId;
    record.type = type;

    player->dynamicRecordChanges.records.push_back(record);
    return player->dynamicRecordChanges.records.size() - 1;
}

const char *DynamicRecordFunctions::GetDynamicRecordRefId(unsigned short pid, unsigned int i) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, "");

    if (i >= player->dynamicRecordChanges.count)
        return "invalid";

    return player->dynamicRecordChanges.records.at(i).refId.c_str();
}

int DynamicRecordFunctions::GetDynamicRecordType(unsigned short pid, unsigned int i) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    if (i >= player->dynamicRecordChanges.count)
        return 0;

    return player->dynamicRecordChanges.records.at(i).type;
}

void DynamicRecordFunctions::SendDynamicRecordChanges(unsigned short pid, bool toOthers) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_PLAYER_DYNAMICRECORD)->setPlayer(player);
    mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_PLAYER_DYNAMICRECORD)->Send(false);

    if(toOthers)
        mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_PLAYER_DYNAMICRECORD)->Send(true);
}

//endregion

//region Custom Spells

void DynamicRecordFunctions::AddCustomSpell(unsigned short pid, int index, const char* spellName) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    ESM::Spell spell;
    spell.mName = spellName;
    spell.mId = player->dynamicRecordChanges.records.at(index).refId;

    player->dynamicRecordChanges.records.at(index).spell = spell;
}

void DynamicRecordFunctions::AddCustomSpellData(unsigned short pid, int index, int type, int cost, int flags) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    player->dynamicRecordChanges.records.at(index).spell.mData.mType = type;
    player->dynamicRecordChanges.records.at(index).spell.mData.mCost = cost;
    player->dynamicRecordChanges.records.at(index).spell.mData.mFlags = flags;
}

void DynamicRecordFunctions::AddCustomSpellEffect(unsigned short pid, int index, short effectId, signed char mSkill, signed char mAttribute, int mRange, int mArea, int mDuration, int mMagnMin, int mMagnMax) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    ESM::ENAMstruct effect;
    effect.mEffectID = effectId;
    effect.mSkill = mSkill;
    effect.mAttribute = mAttribute;
    effect.mRange = mRange;
    effect.mArea = mArea;
    effect.mDuration = mDuration;
    effect.mMagnMin = mMagnMin;
    effect.mMagnMax = mMagnMax;

    player->dynamicRecordChanges.records.at(index).spell.mEffects.mList.push_back(effect);
}

const char *DynamicRecordFunctions::GetSpellName(unsigned short pid, unsigned int i) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, "");

    if (i >= player->dynamicRecordChanges.count)
        return "invalid";

    return player->dynamicRecordChanges.records.at(i).spell.mName.c_str();
}

int DynamicRecordFunctions::GetSpellType(unsigned short pid, unsigned int i) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    if (i >= player->dynamicRecordChanges.count)
        return 0;

    return player->dynamicRecordChanges.records.at(i).spell.mData.mType;
}

int DynamicRecordFunctions::GetSpellCost(unsigned short pid, unsigned int i) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    if (i >= player->dynamicRecordChanges.count)
        return 0;

    return player->dynamicRecordChanges.records.at(i).spell.mData.mCost;
}

int DynamicRecordFunctions::GetSpellFlags(unsigned short pid, unsigned int i) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    if (i >= player->dynamicRecordChanges.count)
        return 0;

    return player->dynamicRecordChanges.records.at(i).spell.mData.mFlags;
}

unsigned int DynamicRecordFunctions::GetSpellEffectCount(unsigned short pid, unsigned int i) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    if (i >= player->dynamicRecordChanges.count)
        return 0;

    return player->dynamicRecordChanges.records.at(i).spell.mEffects.mList.size();
}

short DynamicRecordFunctions::GetSpellEffectId(unsigned short pid, unsigned int i, unsigned int j) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    if (i >= player->dynamicRecordChanges.count)
        return 0;

    return player->dynamicRecordChanges.records.at(i).spell.mEffects.mList.at(j).mEffectID;
}

signed char DynamicRecordFunctions::GetSpellEffectSkill(unsigned short pid, unsigned int i, unsigned int j) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    if (i >= player->dynamicRecordChanges.count)
        return 0;

    return player->dynamicRecordChanges.records.at(i).spell.mEffects.mList.at(j).mSkill;
}

signed char DynamicRecordFunctions::GetSpellEffectAttribute(unsigned short pid, unsigned int i, unsigned int j) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    if (i >= player->dynamicRecordChanges.count)
        return 0;

    return player->dynamicRecordChanges.records.at(i).spell.mEffects.mList.at(j).mAttribute;
}

int DynamicRecordFunctions::GetSpellEffectRange(unsigned short pid, unsigned int i, unsigned int j) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    if (i >= player->dynamicRecordChanges.count)
        return 0;

    return player->dynamicRecordChanges.records.at(i).spell.mEffects.mList.at(j).mRange;
}

int DynamicRecordFunctions::GetSpellEffectArea(unsigned short pid, unsigned int i, unsigned int j) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    if (i >= player->dynamicRecordChanges.count)
        return 0;

    return player->dynamicRecordChanges.records.at(i).spell.mEffects.mList.at(j).mArea;
}

int DynamicRecordFunctions::GetSpellEffectDuration(unsigned short pid, unsigned int i, unsigned int j) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    if (i >= player->dynamicRecordChanges.count)
        return 0;

    return player->dynamicRecordChanges.records.at(i).spell.mEffects.mList.at(j).mDuration;
}

int DynamicRecordFunctions::GetSpellEffectMagnMin(unsigned short pid, unsigned int i, unsigned int j) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    if (i >= player->dynamicRecordChanges.count)
        return 0;

    return player->dynamicRecordChanges.records.at(i).spell.mEffects.mList.at(j).mMagnMin;
}

int DynamicRecordFunctions::GetSpellEffectMagnMax(unsigned short pid, unsigned int i, unsigned int j) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    if (i >= player->dynamicRecordChanges.count)
        return 0;

    return player->dynamicRecordChanges.records.at(i).spell.mEffects.mList.at(j).mMagnMax;
}

//endregion

//region Custom Potions

void DynamicRecordFunctions::AddCustomPotion(unsigned short pid, int index, const char* potionName, const char* model, const char* icon, const char* script) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    ESM::Potion potion;
    potion.mName = potionName;
    potion.mModel = model;
    potion.mIcon = icon;
    potion.mScript = script;
    potion.mId = player->dynamicRecordChanges.records.at(index).refId;

    player->dynamicRecordChanges.records.at(index).potion = potion;
}

void DynamicRecordFunctions::AddCustomPotionData(unsigned short pid, int index, double weight, int value, int autocalc) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    player->dynamicRecordChanges.records.at(index).potion.mData.mWeight = weight;
    player->dynamicRecordChanges.records.at(index).potion.mData.mValue = value;
    player->dynamicRecordChanges.records.at(index).potion.mData.mAutoCalc = autocalc;
}

void DynamicRecordFunctions::AddCustomPotionEffect(unsigned short pid, int index, short effectId, signed char mSkill, signed char mAttribute, int mRange, int mArea, int mDuration, int mMagnMin, int mMagnMax) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    ESM::ENAMstruct effect;
    effect.mEffectID = effectId;
    effect.mSkill = mSkill;
    effect.mAttribute = mAttribute;
    effect.mRange = mRange;
    effect.mArea = mArea;
    effect.mDuration = mDuration;
    effect.mMagnMin = mMagnMin;
    effect.mMagnMax = mMagnMax;

    player->dynamicRecordChanges.records.at(index).potion.mEffects.mList.push_back(effect);
}

const char *DynamicRecordFunctions::GetPotionName(unsigned short pid, unsigned int i) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, "");

    if (i >= player->dynamicRecordChanges.count)
        return "invalid";

    return player->dynamicRecordChanges.records.at(i).potion.mName.c_str();
}

const char *DynamicRecordFunctions::GetPotionModel(unsigned short pid, unsigned int i) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, "");

    if (i >= player->dynamicRecordChanges.count)
        return "invalid";

    return player->dynamicRecordChanges.records.at(i).potion.mModel.c_str();
}

const char *DynamicRecordFunctions::GetPotionIcon(unsigned short pid, unsigned int i) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, "");

    if (i >= player->dynamicRecordChanges.count)
        return "invalid";

    return player->dynamicRecordChanges.records.at(i).potion.mIcon.c_str();
}

const char *DynamicRecordFunctions::GetPotionScript(unsigned short pid, unsigned int i) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, "");

    if (i >= player->dynamicRecordChanges.count)
        return "invalid";

    return player->dynamicRecordChanges.records.at(i).potion.mScript.c_str();
}

float DynamicRecordFunctions::GetPotionWeight(unsigned short pid, unsigned int i) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    if (i >= player->dynamicRecordChanges.count)
        return 0;

    return player->dynamicRecordChanges.records.at(i).potion.mData.mWeight;
}

int DynamicRecordFunctions::GetPotionValue(unsigned short pid, unsigned int i) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    if (i >= player->dynamicRecordChanges.count)
        return 0;

    return player->dynamicRecordChanges.records.at(i).potion.mData.mValue;
}

int DynamicRecordFunctions::GetPotionAutoCalc(unsigned short pid, unsigned int i) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    if (i >= player->dynamicRecordChanges.count)
        return 0;

    return player->dynamicRecordChanges.records.at(i).potion.mData.mAutoCalc;
}

unsigned int DynamicRecordFunctions::GetPotionEffectCount(unsigned short pid, unsigned int i) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    if (i >= player->dynamicRecordChanges.count)
        return 0;

    return player->dynamicRecordChanges.records.at(i).potion.mEffects.mList.size();
}

short DynamicRecordFunctions::GetPotionEffectId(unsigned short pid, unsigned int i, unsigned int j) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    if (i >= player->dynamicRecordChanges.count)
        return 0;

    return player->dynamicRecordChanges.records.at(i).potion.mEffects.mList.at(j).mEffectID;
}

signed char DynamicRecordFunctions::GetPotionEffectSkill(unsigned short pid, unsigned int i, unsigned int j) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    if (i >= player->dynamicRecordChanges.count)
        return 0;

    return player->dynamicRecordChanges.records.at(i).potion.mEffects.mList.at(j).mSkill;
}

signed char DynamicRecordFunctions::GetPotionEffectAttribute(unsigned short pid, unsigned int i, unsigned int j) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    if (i >= player->dynamicRecordChanges.count)
        return 0;

    return player->dynamicRecordChanges.records.at(i).potion.mEffects.mList.at(j).mAttribute;
}

int DynamicRecordFunctions::GetPotionEffectRange(unsigned short pid, unsigned int i, unsigned int j) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    if (i >= player->dynamicRecordChanges.count)
        return 0;

    return player->dynamicRecordChanges.records.at(i).potion.mEffects.mList.at(j).mRange;
}

int DynamicRecordFunctions::GetPotionEffectArea(unsigned short pid, unsigned int i, unsigned int j) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    if (i >= player->dynamicRecordChanges.count)
        return 0;

    return player->dynamicRecordChanges.records.at(i).potion.mEffects.mList.at(j).mArea;
}

int DynamicRecordFunctions::GetPotionEffectDuration(unsigned short pid, unsigned int i, unsigned int j) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    if (i >= player->dynamicRecordChanges.count)
        return 0;

    return player->dynamicRecordChanges.records.at(i).potion.mEffects.mList.at(j).mDuration;
}

int DynamicRecordFunctions::GetPotionEffectMagnMin(unsigned short pid, unsigned int i, unsigned int j) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    if (i >= player->dynamicRecordChanges.count)
        return 0;

    return player->dynamicRecordChanges.records.at(i).potion.mEffects.mList.at(j).mMagnMin;
}

int DynamicRecordFunctions::GetPotionEffectMagnMax(unsigned short pid, unsigned int i, unsigned int j) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    if (i >= player->dynamicRecordChanges.count)
        return 0;

    return player->dynamicRecordChanges.records.at(i).potion.mEffects.mList.at(j).mMagnMax;
}

//endregion

//region Custom Enchantments

void DynamicRecordFunctions::AddCustomEnchantment(unsigned short pid, int index) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    ESM::Enchantment enchantment;
    enchantment.mId = player->dynamicRecordChanges.records.at(index).refId;
    player->dynamicRecordChanges.records.at(index).enchantment = enchantment;
}

void DynamicRecordFunctions::AddCustomEnchantmentData(unsigned short pid, int index, int type, int charge, int autocalc, int cost) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    player->dynamicRecordChanges.records.at(index).enchantment.mData.mType = type;
    player->dynamicRecordChanges.records.at(index).enchantment.mData.mCharge = charge;
    player->dynamicRecordChanges.records.at(index).enchantment.mData.mAutocalc = autocalc;
    player->dynamicRecordChanges.records.at(index).enchantment.mData.mCost = cost;
}

void DynamicRecordFunctions::AddCustomEnchantmentEffect(unsigned short pid, int index, short effectId, signed char mSkill, signed char mAttribute, int mRange, int mArea, int mDuration, int mMagnMin, int mMagnMax) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    ESM::ENAMstruct effect;
    effect.mEffectID = effectId;
    effect.mSkill = mSkill;
    effect.mAttribute = mAttribute;
    effect.mRange = mRange;
    effect.mArea = mArea;
    effect.mDuration = mDuration;
    effect.mMagnMin = mMagnMin;
    effect.mMagnMax = mMagnMax;

    player->dynamicRecordChanges.records.at(index).enchantment.mEffects.mList.push_back(effect);
}

void DynamicRecordFunctions::AddCustomEnchantmentContext(unsigned short pid, int index, int type, int gemCharge, const char* oldItemRefId, const char* newItemRefId, const char* newItemName) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    player->dynamicRecordChanges.records.at(index).enchantmentContext.itemType = type;
    player->dynamicRecordChanges.records.at(index).enchantmentContext.gemCharge = gemCharge;
    player->dynamicRecordChanges.records.at(index).enchantmentContext.oldItemRefId = oldItemRefId;
    player->dynamicRecordChanges.records.at(index).enchantmentContext.newItemRefId = newItemRefId;
    player->dynamicRecordChanges.records.at(index).enchantmentContext.newItemName = newItemName;
}

int DynamicRecordFunctions::GetEnchantmentContextItemType(unsigned short pid, unsigned int i) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    if (i >= player->dynamicRecordChanges.count)
        return 0;

    return player->dynamicRecordChanges.records.at(i).enchantmentContext.itemType;
}

int DynamicRecordFunctions::GetEnchantmentContextGemCharge(unsigned short pid, unsigned int i) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    if (i >= player->dynamicRecordChanges.count)
        return 0;

    return player->dynamicRecordChanges.records.at(i).enchantmentContext.gemCharge;
}

const char* DynamicRecordFunctions::GetEnchantmentContextOldItemRefId(unsigned short pid, unsigned int i) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    if (i >= player->dynamicRecordChanges.count)
        return 0;

    return player->dynamicRecordChanges.records.at(i).enchantmentContext.oldItemRefId.c_str();
}

const char* DynamicRecordFunctions::GetEnchantmentContextNewItemRefId(unsigned short pid, unsigned int i) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    if (i >= player->dynamicRecordChanges.count)
        return 0;

    return player->dynamicRecordChanges.records.at(i).enchantmentContext.newItemRefId.c_str();
}

void DynamicRecordFunctions::SetEnchantmentContextNewItemRefId(unsigned short pid, unsigned int i, const char* newItemRefId) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    if (i >= player->dynamicRecordChanges.count)
        return;

    player->dynamicRecordChanges.records.at(i).enchantmentContext.newItemRefId = newItemRefId;
    return; 
}

const char* DynamicRecordFunctions::GetEnchantmentContextNewItemName(unsigned short pid, unsigned int i) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    if (i >= player->dynamicRecordChanges.count)
        return 0;

    return player->dynamicRecordChanges.records.at(i).enchantmentContext.newItemName.c_str();
}

int DynamicRecordFunctions::GetEnchantmentType(unsigned short pid, unsigned int i) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    if (i >= player->dynamicRecordChanges.count)
        return 0;

    return player->dynamicRecordChanges.records.at(i).enchantment.mData.mType;
}

int DynamicRecordFunctions::GetEnchantmentCharge(unsigned short pid, unsigned int i) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    if (i >= player->dynamicRecordChanges.count)
        return 0;

    return player->dynamicRecordChanges.records.at(i).enchantment.mData.mCharge;
}

int DynamicRecordFunctions::GetEnchantmentAutoCalc(unsigned short pid, unsigned int i) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    if (i >= player->dynamicRecordChanges.count)
        return 0;

    return player->dynamicRecordChanges.records.at(i).enchantment.mData.mAutocalc;
}

int DynamicRecordFunctions::GetEnchantmentCost(unsigned short pid, unsigned int i) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    if (i >= player->dynamicRecordChanges.count)
        return 0;

    return player->dynamicRecordChanges.records.at(i).enchantment.mData.mCost;
}

unsigned int DynamicRecordFunctions::GetEnchantmentEffectCount(unsigned short pid, unsigned int i) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    if (i >= player->dynamicRecordChanges.count)
        return 0;

    return player->dynamicRecordChanges.records.at(i).enchantment.mEffects.mList.size();
}

short DynamicRecordFunctions::GetEnchantmentEffectId(unsigned short pid, unsigned int i, unsigned int j) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    if (i >= player->dynamicRecordChanges.count)
        return 0;

    return player->dynamicRecordChanges.records.at(i).enchantment.mEffects.mList.at(j).mEffectID;
}

signed char DynamicRecordFunctions::GetEnchantmentEffectSkill(unsigned short pid, unsigned int i, unsigned int j) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    if (i >= player->dynamicRecordChanges.count)
        return 0;

    return player->dynamicRecordChanges.records.at(i).enchantment.mEffects.mList.at(j).mSkill;
}

signed char DynamicRecordFunctions::GetEnchantmentEffectAttribute(unsigned short pid, unsigned int i, unsigned int j) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    if (i >= player->dynamicRecordChanges.count)
        return 0;

    return player->dynamicRecordChanges.records.at(i).enchantment.mEffects.mList.at(j).mAttribute;
}

int DynamicRecordFunctions::GetEnchantmentEffectRange(unsigned short pid, unsigned int i, unsigned int j) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    if (i >= player->dynamicRecordChanges.count)
        return 0;

    return player->dynamicRecordChanges.records.at(i).enchantment.mEffects.mList.at(j).mRange;
}

int DynamicRecordFunctions::GetEnchantmentEffectArea(unsigned short pid, unsigned int i, unsigned int j) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    if (i >= player->dynamicRecordChanges.count)
        return 0;

    return player->dynamicRecordChanges.records.at(i).enchantment.mEffects.mList.at(j).mArea;
}

int DynamicRecordFunctions::GetEnchantmentEffectDuration(unsigned short pid, unsigned int i, unsigned int j) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    if (i >= player->dynamicRecordChanges.count)
        return 0;

    return player->dynamicRecordChanges.records.at(i).enchantment.mEffects.mList.at(j).mDuration;
}

int DynamicRecordFunctions::GetEnchantmentEffectMagnMin(unsigned short pid, unsigned int i, unsigned int j) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    if (i >= player->dynamicRecordChanges.count)
        return 0;

    return player->dynamicRecordChanges.records.at(i).enchantment.mEffects.mList.at(j).mMagnMin;
}

int DynamicRecordFunctions::GetEnchantmentEffectMagnMax(unsigned short pid, unsigned int i, unsigned int j) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    if (i >= player->dynamicRecordChanges.count)
        return 0;

    return player->dynamicRecordChanges.records.at(i).enchantment.mEffects.mList.at(j).mMagnMax;
}

//endregion
