#ifndef GUARD_ROGUE_H
#define GUARD_ROGUE_H

// Extra data for pokemon in party
struct RoguePartyMon
{
    bool8 hasPendingEvo : 1;
    u8 lastPopupLevel : 7;

    bool8 isSafariIllegal : 1;
    u8 pad0 : 7;

    u8 pad1[2];
};

STATIC_ASSERT(sizeof(struct RoguePartyMon) == 4, SizeOfRoguePartyMon);

// Minimal version of mon info to allow easy tracking for safari area
// Split into 32bit blocks

//STATIC_ASSERT(sizeof(struct RogueSafariMon) == 8, SizeOfRogueSafariMon);
//STATIC_ASSERT(sizeof(struct RogueSafariMon) == 20, SizeOfRogueSafariMon);

struct RogueRoamerMon
{
    u32 species     : 16;
    u32 hpIV        : 5;
    u32 attackIV    : 5;
    u32 defenseIV   : 5;
    u32 shinyFlag   : 1;

    u32 speedIV     : 5;
    u32 spAttackIV  : 5;
    u32 spDefenseIV : 5;

    u32 abilityNum  : 2; // technically only needs to be 1 for Vanilla
    u32 genderFlag  : 1;
    u32 hpPerc      : 7; // stored as a percentage
    u32 encounerCount : 4;
    u32 unused0     : 3; 

    u32 status      : 16;
    u32 unused1     : 16; 
};

STATIC_ASSERT(sizeof(struct RogueRoamerMon) == 12, SizeOfRogueRoamerMon);

// Adventure Path settings
//
struct RogueAdvPathRoomParams
{
    u8 roomIdx;
    union
    {
        struct
        {
            u8 difficulty;
        } route;
        struct
        {
            u16 species;
            bool8 shinyState;
        } wildDen;
        struct
        {
            u16 species;
            bool8 shinyState;
        } honeyTree;
        struct
        {
            bool8 shinyState;
        } legendary;
        struct 
        {
            u16 trainerNum;
        } boss;
        struct 
        {
            u16 trainerNum;
        } miniboss;
    } perType;
};

struct RogueAdvPathNode
{
    u8 roomType;
    u8 isBridgeActive : 1;
    u8 isLadderActive : 1;
    struct RogueAdvPathRoomParams roomParams;
};

struct RogueAdvPathRoom
{
    struct Coords8 coords;
    struct RogueAdvPathRoomParams roomParams;
    u16 rngSeed;
    u8 roomType;
    u8 connectionMask;
};

struct RogueAdvPath
{
    struct RogueAdvPathRoomParams currentRoomParams;
    struct RogueAdvPathRoom rooms[ROGUE_ADVPATH_ROOM_CAPACITY];
    u16 routeHistoryBuffer[18];
    u8 currentRoomType;
    u8 roomCount;
    u8 pathLength;
    s8 pathMinY;
    s8 pathMaxY;
    u8 isOverviewActive : 1;
    u8 justGenerated : 1;
};


// Adventure Path generation
//
struct RogueAdvPathGenerator // Attach to mode Difficult Option???
{
   u8 minLength;
   u8 maxLength;
   u16 roomWeights[ADVPATH_ROOM_WEIGHT_COUNT];
   u16 maxRoomCount[ADVPATH_ROOM_WEIGHT_COUNT];
   u16 subRoomWeights[ADVPATH_SUBROOM_WEIGHT_COUNT];
};



struct RogueAdventurePhase
{
    u8 levelCap;
    u8 levelStep;
    u16 bossTrainerFlagsInclude;
    u16 bossTrainerFlagsExclude;
    struct RogueAdvPathGenerator pathGenerator;
};

struct RogueAdventureSettings
{
    const struct RogueAdventurePhase* phases;
    u8 phaseCount;
};

struct RogueHubDecoration
{
    u8 x;
    u8 y;
    u8 decorVariant;
    u8 active : 1;
    u8 unused : 7;
};

struct RogueCampaignData_LowBst
{
    u16 scoreSpecies;
};

struct RogueCampaignData_Generic
{
    u16 score;
};

struct RogueWildEncounters
{
    struct RogueRoamerMon roamer;
    u16 species[WILD_ENCOUNTER_TOTAL_CAPACITY];
    u8 catchCounts[WILD_ENCOUNTER_TOTAL_CAPACITY];
    u8 roamerActiveThisPath : 1;
};

// We just want this to be the same size as box pokemon so we can reserve the memory and cast laterpartyPid

struct RoguePokemonFacade
{
    u8 data[104];
};

struct RoguePartySnapshot
{
    u32 partyPersonalities[PARTY_SIZE];
    u16 partySpeciesGfx[PARTY_SIZE];
};

struct RogueRunData
{
    struct RogueWildEncounters wildEncounters;
    struct RoguePartySnapshot partySnapshots[ROGUE_MAX_BOSS_COUNT + 2];
    struct RoguePokemonFacade labParty[LAB_MON_COUNT];
    u16 bossTrainerNums[ROGUE_MAX_BOSS_COUNT];
    u16 rivalSpecies[ROGUE_RIVAL_TOTAL_MON_COUNT];
    u16 legendarySpecies[ADVPATH_LEGEND_COUNT];
    u16 teamEncounterRooms[ADVPATH_TEAM_ENCOUNTER_COUNT];
    u16 dynamicTRMoves[NUM_TECHNICAL_RECORDS];
    u16 partyHeldItems[PARTY_SIZE];
    u16 dynamicTrainerNums[ROGUE_MAX_ACTIVE_TRAINER_COUNT];
    u8 legendaryDifficulties[ADVPATH_LEGEND_COUNT];
    u8 teamEncounterDifficulties[ADVPATH_TEAM_ENCOUNTER_COUNT];
    u8 rivalEncounterDifficulties[ROGUE_RIVAL_MAX_ROUTE_ENCOUNTERS];
    u8 completedBadges[ROGUE_MAX_BOSS_COUNT];
    u8 activeEvoItemFlags[8];
    u8 activeFormItemFlags[16]; // technically this isn't needed for Vanilla
    union
    {
        struct RogueCampaignData_Generic generic;
        struct RogueCampaignData_LowBst lowBst;
    } campaignData;
    u32 honeyTreePokeblockTypeFlags;
    u16 baseSeed;
    u16 rivalTrainerNum;
    u16 teamBossTrainerNum;
    u16 teamEncounterNum;
    u16 enteredRoomCounter;
    u16 currentDifficulty;
    u16 victoryLapTotalWins;
    u8 shrineSpawnDifficulty;
    u8 adventureRoomId;
    u8 currentRouteIndex;
    u8 currentLevelOffset;
    u8 partySnapshotCount;
#ifdef ROGUE_EXPANSION
    u8 megasEnabled : 1;
    u8 zMovesEnabled : 1;
    u8 dynamaxEnabled : 1;
    u8 terastallizeEnabled : 1;
#endif
    u8 rareShopEnabled : 1;
    bool8 isQuickSaveValid : 1;
    bool8 hasPendingRivalBattle : 1;
    bool8 rivalHasShiny : 1;
};

struct RogueRouteMap
{
    u16 layout;
    u16 group;
    u16 num;
#ifdef ROGUE_DEBUG
    const u8 debugName[40];
#endif
};

struct RogueRouteEncounter
{
    u8 dropRarity;
    u16 mapFlags;
    struct RogueRouteMap map;
    const u8 wildTypeTable[3];
};

struct RogueRouteData
{
    u8 routeCount;
    const struct RogueRouteEncounter* routes;
};

struct RogueEncounterMap
{
    u16 encounterId;
    u16 layout;
    u16 group;
    u16 num;
};

struct RogueEncounterData
{
    u8 mapCount;
    const struct RogueEncounterMap* mapTable;
};

struct RogueBattleMusicRedirect
{
    u16 redirectParam;
    u8 redirectType;
    u8 musicPlayer;
};

struct RogueBattleMusic
{
    struct RogueBattleMusicRedirect const* redirects;
    u16 redirectCount;
    u16 encounterMusic;
    u16 battleMusic;
    u16 victoryMusic;
};

struct RogueTeamGeneratorSubset
{
    u16 const* additionalSpecies;
    u32 includedTypeMask;
    u32 excludedTypeMask;
    u32 includedGenMask;
    u32 excludedGenMask;
    u16 additionalSpeciesCount;
    u8 maxSamples;
    u8 isDiversitySubset : 1;
    u8 allowSpeciesDuplicates : 1;
};

struct RogueTeamGenerator
{
    u16 const* queryScriptOverride;
    u16 const* queryScriptPost;
    u16 const* weightScript;
    struct RogueTeamGeneratorSubset const* subsets;
    u8 subsetCount;
    u8 preferredGender;
};

struct RogueTrainer
{
    u8 const* trainerName;
    u8 const* const* encounterText; // TRAINER_STRING_COUNT * N
    u32 classFlags;
    u32 trainerFlags;
    u16 objectEventGfx;
    u16 typeAssignment;
    u16 typeAssignmentGroup;
    u16 preferredPokeballItem;
    u16 potentialShinySpecies;
    u8 levelOverride;
    u8 trainerClass;
    u16 trainerPic;
    u8 preferredWeather;
    u8 musicPlayer;
    u8 encounterTextCount;
    struct RogueTeamGenerator teamGenerator;
};

struct SpeciesTable
{
    u8 wildSpeciesCount;
    const u16* wildSpecies;
    u8 trainerSpeciesCount;
    const u16* trainerSpecies;
};

struct RogueDifficultyConfig
{
    u8 toggleBits[CONFIG_TOGGLE_BYTE_COUNT];
    u8 rangeValues[CONFIG_RANGE_COUNT];
};

struct RogueDebugConfig
{
    u8 toggleBits[DEBUG_TOGGLE_BYTE_COUNT];
    u8 rangeValues[DEBUG_RANGE_COUNT];
};

// Rogue Multiplayer
//

struct RogueNetAdventureState
{
    u16 baseSeed;
    u8 isRunActive : 1;
};

struct RogueNetPlayerProfile
{
    u8 trainerName[PLAYER_NAME_LENGTH + 1];
    u8 playerTrainerId[TRAINER_ID_LENGTH];
    u16 preferredOutfitStyle[3]; // PLAYER_OUTFIT_STYLE_COUNT
    u8 networkId; // assigned by host
    u8 preferredOutfit;
    u8 fallbackOutfit;
    u8 isActive : 1;
};

struct RogueNetPlayerMovement
{
    struct Coords16 pos;
    u8 movementAction;
};

struct RogueNetPlayer
{
    struct RogueNetPlayerMovement movementBuffer[NET_PLAYER_MOVEMENT_BUFFER_SIZE];
    u8 cmdSendBuffer[NET_CMD_BUFFER_SIZE];
    u8 cmdRespBuffer[NET_CMD_BUFFER_SIZE];
    struct Coords16 playerPos;
    struct Coords8 partnerPos;
    u16 partnerMon;
    u16 playerStatusParam;
    u16 playerStatusCounter;
    u8 playerStatus;
    u8 playerStatusSubstate;
    s8 mapGroup;
    s8 mapNum;
    u8 playerFlags;
    u8 adventureDifficulty : 4; // assuming ROGUE_MAX_BOSS_COUNT=14 is max difficulty
    u8 adventureTileNum : 4;
    u8 movementBufferHead : 4; // assuming movementBuffer is 8 long
    u8 currentElevation : 4;
    u8 facingDirection : 4;
    u8 partnerFacingDirection : 4;
};

struct RogueNetHandshake
{
    struct RogueNetPlayerProfile profile;
    u16 saveVersionId;
    u8 state;
    u8 playerId;
    u8 accepted : 1;
    u8 isVersionEx : 1;
};

// Rogue Assistant
//

struct RogueAssistantHeader
{
    u8 rogueVersion;
    u8 rogueDebug;
    u32 rogueAssistantCompatVersion;
    u32 assistantConfirmSize;
    u32 assistantConfirmOffset;
    u32 netMultiplayerSize;
    u32 netHandshakeOffset;
    u32 netHandshakeSize;
    u32 netHandshakeStateOffset;
    u32 netHandshakePlayerIdOffset;
    u32 netGameStateOffset;
    u32 netGameStateSize;
    u32 netPlayerProfileOffset;
    u32 netPlayerProfileSize;
    u32 netPlayerStateOffset;
    u32 netPlayerStateSize;
    u32 netPlayerCount;
    u32 netRequestStateOffset;
    u32 netCurrentStateOffset;
    u32 homeLocalBoxCount;
    u32 homeTotalBoxCount;
    u32 homeBoxSize;
    u32 homeMinimalBoxOffset;
    u32 homeMinimalBoxSize;
    u32 homeDestMonOffset;
    u32 homeDestMonSize;
    u32 homeRemoteIndexOrderOffset;
    u32 homeTrainerIdOffset;
    void const* saveBlock1Ptr;
    void const* saveBlock2Ptr;
    void const* rogueBlockPtr;
    void const* assistantState;
    void const* multiplayerPtr;
    void const* homeBoxPtr;
};

extern const struct RogueAssistantHeader gRogueAssistantHeader;

#ifdef ROGUE_FEATURE_AUTOMATION
struct RogueAutomationHeader
{
    u32 commBufferCapacity;
    u16* commBuffer;
};

extern const struct RogueAutomationHeader gRogueAutomationHeader;
#endif

struct PokemonObjectEventInfo
{
    const u32* defaultPic;
    const u32* shinyPic;
    u8 width;
    u8 height;
    u8 defaultPaletteOffset;
    u8 shinyPaletteOffset;
};

struct RoguePokedexVariant
{
    const u8* displayName;
    const u16* speciesList;
    u16 speciesCount;
    u8 genLimit;
};

struct RoguePokedexRegion
{
    const u8* displayName;
    const u16* variantList;
    u16 variantCount;
};

struct RoguePokemonProfile
{
    struct RoguePokemonCompetitiveSet const* competitiveSets;
    struct LevelUpMove const* levelUpMoves;
    u16 const* tutorMoves;
    u16 monFlags;
    u16 competitiveSetCount;
};

struct RogueRideMonState
{
    u16 monGfx;
    u16 desiredRideSpecies;
    u8 flyingHeight : 6;
    u8 whistleType : 1;
    bool8 flyingState : 1;
};

struct AdventureReplay
{
    struct RogueDifficultyConfig difficultyConfig;
    u16 baseSeed;
    u8 isValid : 1;
};


struct RogueSaveBlock
{
    u16 saveVersion;
    u8 currentBlockFormat;

    // Everything past this point is not safe to read until the block format
    // has been adjusted
    struct AdventureReplay adventureReplay[ROGUE_ADVENTURE_REPLAY_COUNT];
    struct RogueDifficultyConfig difficultyConfig;
    u16 timeOfDayMinutes;
    u8 seasonCounter;
};

struct RogueSpeciesBakedData
{
    u32 evolutionChainTypeFlags : 18;
    u32 eggSpecies : 11;
    u32 unused1 : 3;

    u32 evolutionCount : 8;
    u32 unused2 : 24;
};

struct RogueFollowMonGraphicsInfo
{
    struct ObjectEventGraphicsInfo const* objectEventGfxInfo;
    u16 const* normalPal;
    u16 const* shinyPal;
};

STATIC_ASSERT(sizeof(struct RogueSpeciesBakedData) == 8, SizeOfRogueSpeciesBakedData);

extern const struct RogueRouteData gRogueRouteTable;
extern const struct RogueEncounterData gRogueLegendaryEncounterInfo;
extern const struct RogueEncounterData gRogueTeamEncounterInfo;
extern const struct RogueEncounterData gRogueRestStopEncounterInfo;

extern const struct RogueTrainer gRogueTrainers[];
extern const u16 gRogueTrainerCount;
extern const struct RogueBattleMusic gRogueTrainerMusic[];

extern const struct RoguePokemonProfile gRoguePokemonProfiles[NUM_SPECIES];

extern const u8 gRogueTypeWeatherTable[];
extern const struct RogueEncounterMap gRogueTypeToEliteRoom[];


#endif  // GUARD_ROGUE_H
