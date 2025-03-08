

// When changing this, make sure to:
// -bump ROGUE_SAVE_VERSION in rogue_save.c
// -update SAVE_VER_ID_X_Y_Z enum in rogue_save.h
// -update RogueSave_GetVersionIdFor()
const u8 gText_RogueVersion[] = _("v2.0");

#ifdef ROGUE_EXPANSION
const u8 gText_RogueVersionPrefix[] = _("EX");
#else
const u8 gText_RogueVersionPrefix[] = _("Vanilla");
#endif

#if defined(ROGUE_FEATURE_AUTOMATION)
const u8 gText_RogueVersionSuffix[] = _("(AUTOMATION)");
#elif defined(ROGUE_DEBUG)
const u8 gText_RogueVersionSpacer[] = _(" - ");
const u8 gText_RogueVersionSuffix[] = _("(DEBUG)");
#else
const u8 gText_RogueVersionSpacer[] = _("");
const u8 gText_RogueVersionSuffix[] = _(""); // no subtitle for 2.0
#endif

// UI String
//
const u8 gText_StatusRoute[] = _("Route: {STR_VAR_1}\n");
const u8 gText_StatusBadges[] = _("Orden: {STR_VAR_1}\n");
const u8 gText_StatusScore[] = _("Punkte: {STR_VAR_1}\n");
const u8 gText_StatusTimer[] = _("Zeit: {STR_VAR_1}:{STR_VAR_2}\n");
const u8 gText_StatusClock[] = _("{STR_VAR_1}:{STR_VAR_2}\n");
const u8 gText_StatusSeasonSpring[] = _("·Frühling·");
const u8 gText_StatusSeasonSummer[] = _("·Sommer·");
const u8 gText_StatusSeasonAutumn[] = _("·Herbst·");
const u8 gText_StatusSeasonWinter[] = _("·Winter·");

// Colours aren't exact as they'll be used in battle UI
const u8 gText_MoveEffective[] = _("{COLOR BLUE}{SHADOW DYNAMIC_COLOR6}Neutral");
const u8 gText_MoveNoEffect[] = _("{COLOR TRANSPARENT}{SHADOW BLUE}Keine Wirkung…");
const u8 gText_MoveSuperEffective[] = _("{COLOR GREEN}{SHADOW DYNAMIC_COLOR6}Effektiv!");
const u8 gText_MoveNotVeryEffective[] = _("{COLOR WHITE}{SHADOW DYNAMIC_COLOR6}Nicht Effektiv");
const u8 gText_MoveSlash[] = _("{COLOR BLUE}{SHADOW DYNAMIC_COLOR6}·");
const u8 gText_MoveShortEffective[] = _("{COLOR BLUE}{SHADOW DYNAMIC_COLOR6}Neutrl");
const u8 gText_MoveShortNoEffect[] = _("{COLOR TRANSPARENT}{SHADOW BLUE}Kein Efkt");
const u8 gText_MoveShortSuperEffective[] = _("{COLOR GREEN}{SHADOW DYNAMIC_COLOR6}Effekt");
const u8 gText_MoveShortNotVeryEffective[] = _("{COLOR WHITE}{SHADOW DYNAMIC_COLOR6}NtEfkt");


// Trainers
//
const u8 gText_TrainerName_Default[] = _("Rogue");

const u8 gText_TrainerName_Brendan[] = _("Hans");
const u8 gText_TrainerName_May[] = _("Brigitte");
const u8 gText_TrainerName_Red[] = _("Red");
const u8 gText_TrainerName_Leaf[] = _("Leaf");
const u8 gText_TrainerName_Ethan[] = _("Klarin");
const u8 gText_TrainerName_Lyra[] = _("Lyra");

// Items
//
const u8 gText_EscapeRopeDesc[] = _(
    "Benutze um sofort\n"
    "aus den meisten\n"
    "Begegnungen zu entkommen.");

// Difficulty/Config lab settings
//

//{COLOR DARK_GRAY}{SHADOW DARK_GRAY} <default> orange tint
//{COLOR GREEN}{SHADOW LIGHT_GREEN} no tint
//{COLOR RED}{SHADOW LIGHT_RED} red tint
//{COLOR LIGHT_BLUE}{SHADOW BLUE} green tint
const u8 gText_16Spaces[] = _("                ");
const u8 gText_32Spaces[] = _("                                ");

const u8 gText_DifficultySettings[] = _("Schwierigkeitsgrad Einstellungen");
const u8 gText_DifficultyArrowLeft[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}{LEFT_ARROW}");
const u8 gText_DifficultyArrowRight[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}{RIGHT_ARROW}");

const u8 gText_DifficultyDoesntAffectReward[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}(Belohnungen unverändert)");
const u8 gText_DifficultyRewardLevel[] = _("{FONT_SMALL}{COLOR GREEN}{SHADOW LIGHT_GREEN}Belohnungsstufe: ");

const u8 gText_DifficultyPreset[] = _("Schwierigkeitsgrad");

// Colours on the Settings Screen are out of order and wild
//LIGHT_BLUE = green
//BLUE = light green
//LIGHT_RED = red
//RED = light red
//DARK_GRAY = light yellow
//LIGHT_GRAY = dark yellow
//LIGHT_GREEN = light grey
const u8 gText_DifficultyPresetEasy[] = _("{COLOR LIGHT_BLUE}{SHADOW BLUE}Einfach");
const u8 gText_DifficultyPresetMedium[] = _("{COLOR LIGHT_BLUE}{SHADOW LIGHT_GREEN}Durchschnitt");
const u8 gText_DifficultyPresetHard[] = _("{COLOR LIGHT_RED}{SHADOW LIGHT_GREEN}Schwer");
const u8 gText_DifficultyPresetBrutal[] = _("{COLOR LIGHT_RED}{SHADOW RED}Brutal");
const u8 gText_DifficultyPresetCustom[] = _("{COLOR DARK_GRAY}{SHADOW LIGHT_GREEN}Benutzerdefiniert");

const u8 gText_DifficultyEnabled[] = _("{COLOR LIGHT_BLUE}{SHADOW BLUE}Aktiviert  ");
const u8 gText_DifficultyDisabled[] = _("{COLOR LIGHT_RED}{SHADOW LIGHT_GREEN}Deaktiviert");
const u8 gText_DifficultyModeActive[] = _("{COLOR LIGHT_BLUE}{SHADOW BLUE}Aktiv!");

const u8 gText_DifficultyExpAll[] = _("EP. Alle");
const u8 gText_DifficultyOverLvl[] = _("Über Level");
const u8 gText_DifficultyEVGain[] = _("EV Gewinn");
const u8 gText_DifficultyOverworldMons[] = _("Sichtbare wilde {PKMN}");
const u8 gText_DifficultyBagWipe[] = _("Neustart");
const u8 gText_DifficultySwitchMode[] = _("Wechselmodus");

const u8 gText_DifficultyTrainers[] = _("Trainer");
const u8 gText_DifficultyItems[] = _("Gegenstände");
const u8 gText_DifficultyLegendaries[] = _("Legendäre");

const u8 gText_DifficultyCustomDesc[] = _(
    "{COLOR GREEN}{SHADOW LIGHT_GREEN}"
    "Bearbeite einzelne Einstellungen und passe\n"
    "die Schwierigkeit nach deinem Geschmack an."
);

const u8 gText_AdventureCustomDesc[] = _(
    "{COLOR GREEN}{SHADOW LIGHT_GREEN}"
    "Bearbeite einzelne Einstellungen und passe\n"
    "das Abenteuer nach deinem Geschmack an."
);

const u8 gText_DifficultyTrainersDesc[] = _(
    "{COLOR GREEN}{SHADOW LIGHT_GREEN}"
    "Passt Qualität, Quantität und Stärke\n"
    "aller Trainer-{PKMN} an."
);

const u8 gText_DifficultyItemsDesc[] = _(
    "{COLOR GREEN}{SHADOW LIGHT_GREEN}"
    "TODO. Dies muss überarbeitet werden..."
);

const u8 gText_DifficultyLegendariesDesc[] = _(
    "{COLOR GREEN}{SHADOW LIGHT_GREEN}"
    "Verringert Qualität und Quantität von\n"
    "Legendären {PKMN}-Begegnungen."
);

// Campaigns
//
const u8 gText_CampaignHofTitle[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}{STR_VAR_1}");

const u8 gText_Campaign_None[] = _("???");
const u8 gText_Campaign_LowBST[] = _("BST CUP");
const u8 gText_Campaign_Classic[] = _("Klassischer Modus");
const u8 gText_Campaign_MiniBossBattler[] = _("Kampf Süchtiger");
const u8 gText_Campaign_AutoBattler[] = _("Auto Kämpfer");
const u8 gText_Campaign_LaterManner[] = _("LaterManner Modus");
const u8 gText_Campaign_PokeballLimit[] = _("Begrenzte Fänge");
const u8 gText_Campaign_OneHp[] = _("Ein Treffer Modus");

// Debug
//
#ifdef ROGUE_DEBUG
const u8 gText_RogueDebug_Header[] = _("ROGUE DEBUG");
const u8 gText_RogueDebug_Save[] = _("\nSpeichern: ");
const u8 gText_RogueDebug_Room[] = _("\nRaum: ");
const u8 gText_RogueDebug_BossRoom[] = _("\nBossRaum: ");
const u8 gText_RogueDebug_Difficulty[] = _("\nSchw: ");
const u8 gText_RogueDebug_PlayerLvl[] = _("\nSpieler lvl: ");
const u8 gText_RogueDebug_WildLvl[] = _("\nWilde lvl: ");
const u8 gText_RogueDebug_WildCount[] = _("\nWilde Opt: ");
const u8 gText_RogueDebug_ItemCount[] = _("\nGegenst Opt: ");
const u8 gText_RogueDebug_TrainerCount[] = _("\nTrainer Opt: ");
const u8 gText_RogueDebug_Seed[] = _("\nSaat: ");

const u8 gText_RogueDebug_AdvHeader[] = _("ROGUE ADVPATH");
const u8 gText_RogueDebug_AdvCount[] = _("\nAnzahl: ");
const u8 gText_RogueDebug_X[] = _("\nX: ");
const u8 gText_RogueDebug_Y[] = _("\nY: ");
#endif