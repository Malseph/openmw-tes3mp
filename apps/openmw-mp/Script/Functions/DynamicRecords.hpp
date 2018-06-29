#ifndef OPENMW_DYNAMICRECORDAPI_HPP
#define OPENMW_DYNAMICRECORDAPI_HPP

#define DYNAMICRECORDAPI \
    {"InitializeDynamicRecordChanges", DynamicRecordFunctions::InitializeDynamicRecordChanges},\
    \
    {"GetDynamicRecordChangesSize",    DynamicRecordFunctions::GetDynamicRecordChangesSize},\
    {"GetDynamicRecordChangesAction",  DynamicRecordFunctions::GetDynamicRecordChangesAction},\
    \
    {"SetDynamicRecordChangesAction",  DynamicRecordFunctions::SetDynamicRecordChangesAction},\
    {"AddDynamicRecord",                   DynamicRecordFunctions::AddDynamicRecord},\
    {"SetDynamicRecordRefId",                 DynamicRecordFunctions::SetDynamicRecordRefId},\
    \
    {"GetDynamicRecordRefId",                 DynamicRecordFunctions::GetDynamicRecordRefId},\
    {"GetDynamicRecordType",                 DynamicRecordFunctions::GetDynamicRecordType},\
    \
    {"SendDynamicRecordChanges",       DynamicRecordFunctions::SendDynamicRecordChanges},\
    \
    \
    {"AddCustomSpell",                   DynamicRecordFunctions::AddCustomSpell},\
    {"AddCustomSpellData",                   DynamicRecordFunctions::AddCustomSpellData},\
    {"AddCustomSpellEffect",                   DynamicRecordFunctions::AddCustomSpellEffect},\
    \
    {"GetSpellName",                 DynamicRecordFunctions::GetSpellName},\
    {"GetSpellType",                 DynamicRecordFunctions::GetSpellType},\
    {"GetSpellCost",                 DynamicRecordFunctions::GetSpellCost},\
    {"GetSpellFlags",                 DynamicRecordFunctions::GetSpellFlags},\
    {"GetSpellEffectCount",                 DynamicRecordFunctions::GetSpellEffectCount},\
    {"GetSpellEffectId",                 DynamicRecordFunctions::GetSpellEffectId},\
    {"GetSpellEffectSkill",                 DynamicRecordFunctions::GetSpellEffectSkill},\
    {"GetSpellEffectAttribute",                 DynamicRecordFunctions::GetSpellEffectAttribute},\
    {"GetSpellEffectRange",                 DynamicRecordFunctions::GetSpellEffectRange},\
    {"GetSpellEffectArea",                 DynamicRecordFunctions::GetSpellEffectArea},\
    {"GetSpellEffectDuration",                 DynamicRecordFunctions::GetSpellEffectDuration},\
    {"GetSpellEffectMagnMin",                 DynamicRecordFunctions::GetSpellEffectMagnMin},\
    {"GetSpellEffectMagnMax",                 DynamicRecordFunctions::GetSpellEffectMagnMax},\
    \
    \
    {"AddCustomPotion",                   DynamicRecordFunctions::AddCustomPotion},\
    {"AddCustomPotionData",                   DynamicRecordFunctions::AddCustomPotionData},\
    {"AddCustomPotionEffect",                   DynamicRecordFunctions::AddCustomPotionEffect},\
    \
    {"GetPotionName",                 DynamicRecordFunctions::GetPotionName},\
    {"GetPotionModel",                 DynamicRecordFunctions::GetPotionModel},\
    {"GetPotionIcon",                 DynamicRecordFunctions::GetPotionIcon},\
    {"GetPotionScript",                 DynamicRecordFunctions::GetPotionScript},\
    {"GetPotionWeight",                 DynamicRecordFunctions::GetPotionWeight},\
    {"GetPotionValue",                 DynamicRecordFunctions::GetPotionValue},\
    {"GetPotionAutoCalc",                 DynamicRecordFunctions::GetPotionAutoCalc},\
    {"GetPotionEffectCount",                 DynamicRecordFunctions::GetPotionEffectCount},\
    {"GetPotionEffectId",                 DynamicRecordFunctions::GetPotionEffectId},\
    {"GetPotionEffectSkill",                 DynamicRecordFunctions::GetPotionEffectSkill},\
    {"GetPotionEffectAttribute",                 DynamicRecordFunctions::GetPotionEffectAttribute},\
    {"GetPotionEffectRange",                 DynamicRecordFunctions::GetPotionEffectRange},\
    {"GetPotionEffectArea",                 DynamicRecordFunctions::GetPotionEffectArea},\
    {"GetPotionEffectDuration",                 DynamicRecordFunctions::GetPotionEffectDuration},\
    {"GetPotionEffectMagnMin",                 DynamicRecordFunctions::GetPotionEffectMagnMin},\
    {"GetPotionEffectMagnMax",                 DynamicRecordFunctions::GetPotionEffectMagnMax},\
    \
    \
    {"AddCustomEnchantment",                   DynamicRecordFunctions::AddCustomEnchantment},\
    {"AddCustomEnchantmentData",                   DynamicRecordFunctions::AddCustomEnchantmentData},\
    {"AddCustomEnchantmentEffect",                   DynamicRecordFunctions::AddCustomEnchantmentEffect},\
    {"AddCustomEnchantmentContext",                   DynamicRecordFunctions::AddCustomEnchantmentContext},\
    \
    {"GetEnchantmentType",                 DynamicRecordFunctions::GetEnchantmentType},\
    {"GetEnchantmentCharge",                 DynamicRecordFunctions::GetEnchantmentCharge},\
    {"GetEnchantmentAutoCalc",                 DynamicRecordFunctions::GetEnchantmentAutoCalc},\
    {"GetEnchantmentCost",                 DynamicRecordFunctions::GetEnchantmentCost},\
    \
    {"GetEnchantmentContextItemType",                 DynamicRecordFunctions::GetEnchantmentContextItemType},\
    {"GetEnchantmentContextOldItemRefId",                 DynamicRecordFunctions::GetEnchantmentContextOldItemRefId},\
    {"GetEnchantmentContextNewItemName",                 DynamicRecordFunctions::GetEnchantmentContextNewItemName},\
    {"GetEnchantmentContextNewItemRefId",                 DynamicRecordFunctions::GetEnchantmentContextNewItemRefId},\
    {"SetEnchantmentContextNewItemRefId",               DynamicRecordFunctions::SetEnchantmentContextNewItemRefId},\
    {"GetEnchantmentContextGemCharge",                 DynamicRecordFunctions::GetEnchantmentContextGemCharge},\
    \
    {"GetEnchantmentEffectCount",                 DynamicRecordFunctions::GetEnchantmentEffectCount},\
    {"GetEnchantmentEffectId",                 DynamicRecordFunctions::GetEnchantmentEffectId},\
    {"GetEnchantmentEffectSkill",                 DynamicRecordFunctions::GetEnchantmentEffectSkill},\
    {"GetEnchantmentEffectAttribute",                 DynamicRecordFunctions::GetEnchantmentEffectAttribute},\
    {"GetEnchantmentEffectRange",                 DynamicRecordFunctions::GetEnchantmentEffectRange},\
    {"GetEnchantmentEffectArea",                 DynamicRecordFunctions::GetEnchantmentEffectArea},\
    {"GetEnchantmentEffectDuration",                 DynamicRecordFunctions::GetEnchantmentEffectDuration},\
    {"GetEnchantmentEffectMagnMin",                 DynamicRecordFunctions::GetEnchantmentEffectMagnMin},\
    {"GetEnchantmentEffectMagnMax",                 DynamicRecordFunctions::GetEnchantmentEffectMagnMax}


class DynamicRecordFunctions
{
public:

    //region Generic Functions

    /**
    * \brief Clear the last recorded spellbook changes for a player.
    *
    * This is used to initialize the sending of new PlayerSpellbook packets.
    *
    * \param pid The player ID whose spellbook changes should be used.
    * \return void
    */
    static void InitializeDynamicRecordChanges(unsigned short pid) noexcept;

    /**
    * \brief Get the number of indexes in a player's latest spellbook changes.
    *
    * \param pid The player ID whose spellbook changes should be used.
    * \return The number of indexes.
    */
    static unsigned int GetDynamicRecordChangesSize(unsigned short pid) noexcept;

    /**
    * \brief Get the action type used in a player's latest spellbook changes.
    *
    * \param pid The player ID whose faction changes should be used.
    * \return The action type (0 for SET, 1 for ADD, 2 for REMOVE).
    */
    static unsigned int GetDynamicRecordChangesAction(unsigned short pid) noexcept;

    /**
    * \brief Set the action type in a player's spellbook changes.
    *
    * \param pid The player ID whose spellbook changes should be used.
    * \param action The action (0 for SET, 1 for ADD, 2 for REMOVE).
    * \return void
    */
    static void SetDynamicRecordChangesAction(unsigned short pid, unsigned char action) noexcept;

    static void SetDynamicRecordRefId(unsigned short pid, unsigned int i, const char* refId) noexcept;

    /**
    * \brief Add a new spell to the spellbook changes for a player.
    *
    * \param pid The player ID whose spellbook changes should be used.
    * \param refId The spellId of the spell.
    * \param type The spellId of the spell.
    * \return void
    */
    static int AddDynamicRecord(unsigned short pid, const char* refId, int type) noexcept;

    /**
    * \brief Get the spellId at a certain index in a player's latest spellbook changes.
    *
    * \param pid The player ID whose spellbook changes should be used.
    * \param i The index of the spell.
    * \return The spellId.
    */
    static const char *GetDynamicRecordRefId(unsigned short pid, unsigned int i) noexcept;

    static int GetDynamicRecordType(unsigned short pid, unsigned int i) noexcept;

    /**
    * \brief Send a PlayerSpellbook packet with a player's recorded spellbook changes.
    *
    * \param pid The player ID whose spellbook changes should be used.
    * \param toOthers Whether this packet should be sent only to other players or
    *                 only to the player it is about.
    * \return void
    */
    static void SendDynamicRecordChanges(unsigned short pid, bool toOthers = false) noexcept;

    //endregion

    //region Spells

    /**
    * \brief Add a new custom spell to the spellbook changes for a player.
    *
    * \param pid The player ID whose spellbook changes should be used.
    * \param index The index of the spell in the player's changes.
    * \param spellName The name of the spell.
    * \return void
    */
    static void AddCustomSpell(unsigned short pid, int index, const char* spellName) noexcept;

    /**
    * \brief Add custom spell data to the spellbook changes for a player.
    *
    * \param pid The player ID whose spellbook changes should be used.
    * \param index The index of the spell in the player's changes.
    * \param type The type of the spell.
    * \param cost The cost of the spell.
    * \param flags The flags of the spell.
    * \return void
    */
    static void AddCustomSpellData(unsigned short pid, int index, int type, int cost, int flags) noexcept;

    /**
    * \brief Add custom spell effect to the spellbook changes for a player.
    *
    * \param pid The player ID whose spellbook changes should be used.
    * \param index The index of the spell in the player's changes.
    * \param effectId The effectId of the spell effect.
    * \param mSkill The skill affected by the spell effect.
    * \param mAttribute The attribute affected by the spell effect.
    * \param mRange The range of the spell effect.
    * \param mArea The area of the spell effect.
    * \param mDuration The duration of the spell effect.
    * \param mMagnMin The minimum magnitude of the spell effect.
    * \param mMagnMax The maximum magnitude of the spell effect.
    * \return void
    */
    static void AddCustomSpellEffect(unsigned short pid, int index, short effectId, signed char mSkill, signed char mAttribute, int mRange, int mArea, int mDuration, int mMagnMin, int mMagnMax) noexcept;

    /**
    * \brief Get the name of the spell at a certain index in a player's latest spellbook changes.
    *
    * \param pid The player ID whose spellbook changes should be used.
    * \param i The index of the spell.
    * \return The spell name.
    */
    static const char *GetSpellName(unsigned short pid, unsigned int i) noexcept;

    /**
    * \brief Get the type of the spell at a certain index in a player's latest spellbook changes.
    *
    * \param pid The player ID whose spellbook changes should be used.
    * \param i The index of the spell.
    * \return The spell type.
    */
    static int GetSpellType(unsigned short pid, unsigned int i) noexcept;

    /**
    * \brief Get the cost of the spell at a certain index in a player's latest spellbook changes.
    *
    * \param pid The player ID whose spellbook changes should be used.
    * \param i The index of the spell.
    * \return The spell cost.
    */
    static int GetSpellCost(unsigned short pid, unsigned int i) noexcept;

    /**
    * \brief Get the flags of the spell at a certain index in a player's latest spellbook changes.
    *
    * \param pid The player ID whose spellbook changes should be used.
    * \param i The index of the spell.
    * \return The spell flags.
    */
    static int GetSpellFlags(unsigned short pid, unsigned int i) noexcept;

    /**
    * \brief Get the number of effects on the spell at a certain index in a player's latest spellbook changes.
    *
    * \param pid The player ID whose spellbook changes should be used.
    * \param i The index of the spell.
    * \return The spell effect count.
    */
    static unsigned int GetSpellEffectCount(unsigned short pid, unsigned int i) noexcept;

    /**
    * \brief Get the effectId of the effect at a certain index in the spell at another certain index in a player's latest spellbook changes.
    *
    * \param pid The player ID whose spellbook changes should be used.
    * \param i The index of the spell.
    * \param j The index of the effect.
    * \return The effectId.
    */
    static short GetSpellEffectId(unsigned short pid, unsigned int i, unsigned int j) noexcept;

    /**
    * \brief Get the affected skill of the effect at a certain index in the spell at another certain index in a player's latest spellbook changes.
    *
    * \param pid The player ID whose spellbook changes should be used.
    * \param i The index of the spell.
    * \param j The index of the effect.
    * \return The affected skill.
    */
    static signed char GetSpellEffectSkill(unsigned short pid, unsigned int i, unsigned int j) noexcept;

    /**
    * \brief Get the affected attribute of the effect at a certain index in the spell at another certain index in a player's latest spellbook changes.
    *
    * \param pid The player ID whose spellbook changes should be used.
    * \param i The index of the spell.
    * \param j The index of the effect.
    * \return The affected attribute.
    */
    static signed char GetSpellEffectAttribute(unsigned short pid, unsigned int i, unsigned int j) noexcept;

    /**
    * \brief Get the range of the effect at a certain index in the spell at another certain index in a player's latest spellbook changes.
    *
    * \param pid The player ID whose spellbook changes should be used.
    * \param i The index of the spell.
    * \param j The index of the effect.
    * \return The range.
    */
    static int GetSpellEffectRange(unsigned short pid, unsigned int i, unsigned int j) noexcept;

    /**
    * \brief Get the area of the effect at a certain index in the spell at another certain index in a player's latest spellbook changes.
    *
    * \param pid The player ID whose spellbook changes should be used.
    * \param i The index of the spell.
    * \param j The index of the effect.
    * \return The area.
    */
    static int GetSpellEffectArea(unsigned short pid, unsigned int i, unsigned int j) noexcept;

    /**
    * \brief Get the duration of the effect at a certain index in the spell at another certain index in a player's latest spellbook changes.
    *
    * \param pid The player ID whose spellbook changes should be used.
    * \param i The index of the spell.
    * \param j The index of the effect.
    * \return The duration.
    */
    static int GetSpellEffectDuration(unsigned short pid, unsigned int i, unsigned int j) noexcept;

    /**
    * \brief Get the minimum magnitude of the effect at a certain index in the spell at another certain index in a player's latest spellbook changes.
    *
    * \param pid The player ID whose spellbook changes should be used.
    * \param i The index of the spell.
    * \param j The index of the effect.
    * \return The minimum magnitude.
    */
    static int GetSpellEffectMagnMin(unsigned short pid, unsigned int i, unsigned int j) noexcept;

    /**
    * \brief Get the maximum magnitude of the effect at a certain index in the spell at another certain index in a player's latest spellbook changes.
    *
    * \param pid The player ID whose spellbook changes should be used.
    * \param i The index of the spell.
    * \param j The index of the effect.
    * \return The maximum magnitude.
    */
    static int GetSpellEffectMagnMax(unsigned short pid, unsigned int i, unsigned int j) noexcept;

    //endregion

    //region Potions

    /**
    * \brief Add a new custom spell to the spellbook changes for a player.
    *
    * \param pid The player ID whose spellbook changes should be used.
    * \param index The index of the spell in the player's changes.
    * \param spellName The name of the spell.
    * \return void
    */
    static void AddCustomPotion(unsigned short pid, int index, const char* potionName, const char* model, const char* icon, const char* script) noexcept;

    /**
    * \brief Add custom spell data to the spellbook changes for a player.
    *
    * \param pid The player ID whose spellbook changes should be used.
    * \param index The index of the spell in the player's changes.
    * \param type The type of the spell.
    * \param cost The cost of the spell.
    * \param flags The flags of the spell.
    * \return void
    */
    static void AddCustomPotionData(unsigned short pid, int index, double weight, int value, int autocalc) noexcept;

    /**
    * \brief Add custom spell effect to the spellbook changes for a player.
    *
    * \param pid The player ID whose spellbook changes should be used.
    * \param index The index of the spell in the player's changes.
    * \param effectId The effectId of the spell effect.
    * \param mSkill The skill affected by the spell effect.
    * \param mAttribute The attribute affected by the spell effect.
    * \param mRange The range of the spell effect.
    * \param mArea The area of the spell effect.
    * \param mDuration The duration of the spell effect.
    * \param mMagnMin The minimum magnitude of the spell effect.
    * \param mMagnMax The maximum magnitude of the spell effect.
    * \return void
    */
    static void AddCustomPotionEffect(unsigned short pid, int index, short effectId, signed char mSkill, signed char mAttribute, int mRange, int mArea, int mDuration, int mMagnMin, int mMagnMax) noexcept;

    /**
    * \brief Get the name of the spell at a certain index in a player's latest spellbook changes.
    *
    * \param pid The player ID whose spellbook changes should be used.
    * \param i The index of the spell.
    * \return The spell name.
    */
    static const char *GetPotionName(unsigned short pid, unsigned int i) noexcept;

    /**
    * \brief Get the name of the spell at a certain index in a player's latest spellbook changes.
    *
    * \param pid The player ID whose spellbook changes should be used.
    * \param i The index of the spell.
    * \return The spell name.
    */
    static const char *GetPotionModel(unsigned short pid, unsigned int i) noexcept;

    /**
    * \brief Get the name of the spell at a certain index in a player's latest spellbook changes.
    *
    * \param pid The player ID whose spellbook changes should be used.
    * \param i The index of the spell.
    * \return The spell name.
    */
    static const char *GetPotionIcon(unsigned short pid, unsigned int i) noexcept;

    /**
    * \brief Get the name of the spell at a certain index in a player's latest spellbook changes.
    *
    * \param pid The player ID whose spellbook changes should be used.
    * \param i The index of the spell.
    * \return The spell name.
    */
    static const char *GetPotionScript(unsigned short pid, unsigned int i) noexcept;

    /**
    * \brief Get the type of the spell at a certain index in a player's latest spellbook changes.
    *
    * \param pid The player ID whose spellbook changes should be used.
    * \param i The index of the spell.
    * \return The spell type.
    */
    static float GetPotionWeight(unsigned short pid, unsigned int i) noexcept;

    /**
    * \brief Get the cost of the spell at a certain index in a player's latest spellbook changes.
    *
    * \param pid The player ID whose spellbook changes should be used.
    * \param i The index of the spell.
    * \return The spell cost.
    */
    static int GetPotionValue(unsigned short pid, unsigned int i) noexcept;

    /**
    * \brief Get the flags of the spell at a certain index in a player's latest spellbook changes.
    *
    * \param pid The player ID whose spellbook changes should be used.
    * \param i The index of the spell.
    * \return The spell flags.
    */
    static int GetPotionAutoCalc(unsigned short pid, unsigned int i) noexcept;

    /**
    * \brief Get the number of effects on the spell at a certain index in a player's latest spellbook changes.
    *
    * \param pid The player ID whose spellbook changes should be used.
    * \param i The index of the spell.
    * \return The spell effect count.
    */
    static unsigned int GetPotionEffectCount(unsigned short pid, unsigned int i) noexcept;

    /**
    * \brief Get the effectId of the effect at a certain index in the spell at another certain index in a player's latest spellbook changes.
    *
    * \param pid The player ID whose spellbook changes should be used.
    * \param i The index of the spell.
    * \param j The index of the effect.
    * \return The effectId.
    */
    static short GetPotionEffectId(unsigned short pid, unsigned int i, unsigned int j) noexcept;

    /**
    * \brief Get the affected skill of the effect at a certain index in the spell at another certain index in a player's latest spellbook changes.
    *
    * \param pid The player ID whose spellbook changes should be used.
    * \param i The index of the spell.
    * \param j The index of the effect.
    * \return The affected skill.
    */
    static signed char GetPotionEffectSkill(unsigned short pid, unsigned int i, unsigned int j) noexcept;

    /**
    * \brief Get the affected attribute of the effect at a certain index in the spell at another certain index in a player's latest spellbook changes.
    *
    * \param pid The player ID whose spellbook changes should be used.
    * \param i The index of the spell.
    * \param j The index of the effect.
    * \return The affected attribute.
    */
    static signed char GetPotionEffectAttribute(unsigned short pid, unsigned int i, unsigned int j) noexcept;

    /**
    * \brief Get the range of the effect at a certain index in the spell at another certain index in a player's latest spellbook changes.
    *
    * \param pid The player ID whose spellbook changes should be used.
    * \param i The index of the spell.
    * \param j The index of the effect.
    * \return The range.
    */
    static int GetPotionEffectRange(unsigned short pid, unsigned int i, unsigned int j) noexcept;

    /**
    * \brief Get the area of the effect at a certain index in the spell at another certain index in a player's latest spellbook changes.
    *
    * \param pid The player ID whose spellbook changes should be used.
    * \param i The index of the spell.
    * \param j The index of the effect.
    * \return The area.
    */
    static int GetPotionEffectArea(unsigned short pid, unsigned int i, unsigned int j) noexcept;

    /**
    * \brief Get the duration of the effect at a certain index in the spell at another certain index in a player's latest spellbook changes.
    *
    * \param pid The player ID whose spellbook changes should be used.
    * \param i The index of the spell.
    * \param j The index of the effect.
    * \return The duration.
    */
    static int GetPotionEffectDuration(unsigned short pid, unsigned int i, unsigned int j) noexcept;

    /**
    * \brief Get the minimum magnitude of the effect at a certain index in the spell at another certain index in a player's latest spellbook changes.
    *
    * \param pid The player ID whose spellbook changes should be used.
    * \param i The index of the spell.
    * \param j The index of the effect.
    * \return The minimum magnitude.
    */
    static int GetPotionEffectMagnMin(unsigned short pid, unsigned int i, unsigned int j) noexcept;

    /**
    * \brief Get the maximum magnitude of the effect at a certain index in the spell at another certain index in a player's latest spellbook changes.
    *
    * \param pid The player ID whose spellbook changes should be used.
    * \param i The index of the spell.
    * \param j The index of the effect.
    * \return The maximum magnitude.
    */
    static int GetPotionEffectMagnMax(unsigned short pid, unsigned int i, unsigned int j) noexcept;

    //endregion

    //region Enchantments

    /**
    * \brief Add a new custom spell to the spellbook changes for a player.
    *
    * \param pid The player ID whose spellbook changes should be used.
    * \param index The index of the spell in the player's changes.
    * \param spellName The name of the spell.
    * \return void
    */
    static void AddCustomEnchantment(unsigned short pid, int index) noexcept;

    /**
    * \brief Add custom spell data to the spellbook changes for a player.
    *
    * \param pid The player ID whose spellbook changes should be used.
    * \param index The index of the spell in the player's changes.
    * \param type The type of the spell.
    * \param cost The cost of the spell.
    * \param flags The flags of the spell.
    * \return void
    */
    static void AddCustomEnchantmentData(unsigned short pid, int index, int type, int charge, int autocalc, int cost) noexcept;

    /**
    * \brief Add custom spell effect to the spellbook changes for a player.
    *
    * \param pid The player ID whose spellbook changes should be used.
    * \param index The index of the spell in the player's changes.
    * \param effectId The effectId of the spell effect.
    * \param mSkill The skill affected by the spell effect.
    * \param mAttribute The attribute affected by the spell effect.
    * \param mRange The range of the spell effect.
    * \param mArea The area of the spell effect.
    * \param mDuration The duration of the spell effect.
    * \param mMagnMin The minimum magnitude of the spell effect.
    * \param mMagnMax The maximum magnitude of the spell effect.
    * \return void
    */
    static void AddCustomEnchantmentEffect(unsigned short pid, int index, short effectId, signed char mSkill, signed char mAttribute, int mRange, int mArea, int mDuration, int mMagnMin, int mMagnMax) noexcept;

    static void AddCustomEnchantmentContext(unsigned short pid, int index, int type, int gemCharge, const char* oldItemRefId, const char* newItemRefId, const char* newItemName) noexcept;

    static int GetEnchantmentContextItemType(unsigned short pid, unsigned int i) noexcept;

    static const char* GetEnchantmentContextOldItemRefId(unsigned short pid, unsigned int i) noexcept;

    static const char* GetEnchantmentContextNewItemName(unsigned short pid, unsigned int i) noexcept;

    static const char* GetEnchantmentContextNewItemRefId(unsigned short pid, unsigned int i) noexcept;

    static void SetEnchantmentContextNewItemRefId(unsigned short pid, unsigned int i, const char* newItemRefId) noexcept;

    static int GetEnchantmentContextGemCharge(unsigned short pid, unsigned int i) noexcept;


    /**
    * \brief Get the cost of the spell at a certain index in a player's latest spellbook changes.
    *
    * \param pid The player ID whose spellbook changes should be used.
    * \param i The index of the spell.
    * \return The spell cost.
    */
    static int GetEnchantmentType(unsigned short pid, unsigned int i) noexcept;

    /**
    * \brief Get the cost of the spell at a certain index in a player's latest spellbook changes.
    *
    * \param pid The player ID whose spellbook changes should be used.
    * \param i The index of the spell.
    * \return The spell cost.
    */
    static int GetEnchantmentCharge(unsigned short pid, unsigned int i) noexcept;

    /**
    * \brief Get the cost of the spell at a certain index in a player's latest spellbook changes.
    *
    * \param pid The player ID whose spellbook changes should be used.
    * \param i The index of the spell.
    * \return The spell cost.
    */
    static int GetEnchantmentAutoCalc(unsigned short pid, unsigned int i) noexcept;

    /**
    * \brief Get the cost of the spell at a certain index in a player's latest spellbook changes.
    *
    * \param pid The player ID whose spellbook changes should be used.
    * \param i The index of the spell.
    * \return The spell cost.
    */
    static int GetEnchantmentCost(unsigned short pid, unsigned int i) noexcept;

    static unsigned int GetEnchantmentEffectCount(unsigned short pid, unsigned int i) noexcept;

    /**
    * \brief Get the effectId of the effect at a certain index in the spell at another certain index in a player's latest spellbook changes.
    *
    * \param pid The player ID whose spellbook changes should be used.
    * \param i The index of the spell.
    * \param j The index of the effect.
    * \return The effectId.
    */
    static short GetEnchantmentEffectId(unsigned short pid, unsigned int i, unsigned int j) noexcept;

    /**
    * \brief Get the affected skill of the effect at a certain index in the spell at another certain index in a player's latest spellbook changes.
    *
    * \param pid The player ID whose spellbook changes should be used.
    * \param i The index of the spell.
    * \param j The index of the effect.
    * \return The affected skill.
    */
    static signed char GetEnchantmentEffectSkill(unsigned short pid, unsigned int i, unsigned int j) noexcept;

    /**
    * \brief Get the affected attribute of the effect at a certain index in the spell at another certain index in a player's latest spellbook changes.
    *
    * \param pid The player ID whose spellbook changes should be used.
    * \param i The index of the spell.
    * \param j The index of the effect.
    * \return The affected attribute.
    */
    static signed char GetEnchantmentEffectAttribute(unsigned short pid, unsigned int i, unsigned int j) noexcept;

    /**
    * \brief Get the range of the effect at a certain index in the spell at another certain index in a player's latest spellbook changes.
    *
    * \param pid The player ID whose spellbook changes should be used.
    * \param i The index of the spell.
    * \param j The index of the effect.
    * \return The range.
    */
    static int GetEnchantmentEffectRange(unsigned short pid, unsigned int i, unsigned int j) noexcept;

    /**
    * \brief Get the area of the effect at a certain index in the spell at another certain index in a player's latest spellbook changes.
    *
    * \param pid The player ID whose spellbook changes should be used.
    * \param i The index of the spell.
    * \param j The index of the effect.
    * \return The area.
    */
    static int GetEnchantmentEffectArea(unsigned short pid, unsigned int i, unsigned int j) noexcept;

    /**
    * \brief Get the duration of the effect at a certain index in the spell at another certain index in a player's latest spellbook changes.
    *
    * \param pid The player ID whose spellbook changes should be used.
    * \param i The index of the spell.
    * \param j The index of the effect.
    * \return The duration.
    */
    static int GetEnchantmentEffectDuration(unsigned short pid, unsigned int i, unsigned int j) noexcept;

    /**
    * \brief Get the minimum magnitude of the effect at a certain index in the spell at another certain index in a player's latest spellbook changes.
    *
    * \param pid The player ID whose spellbook changes should be used.
    * \param i The index of the spell.
    * \param j The index of the effect.
    * \return The minimum magnitude.
    */
    static int GetEnchantmentEffectMagnMin(unsigned short pid, unsigned int i, unsigned int j) noexcept;

    /**
    * \brief Get the maximum magnitude of the effect at a certain index in the spell at another certain index in a player's latest spellbook changes.
    *
    * \param pid The player ID whose spellbook changes should be used.
    * \param i The index of the spell.
    * \param j The index of the effect.
    * \return The maximum magnitude.
    */
    static int GetEnchantmentEffectMagnMax(unsigned short pid, unsigned int i, unsigned int j) noexcept;

    //endregion

private:

};

#endif //OPENMW_DYNAMICRECORDAPI_HPP
