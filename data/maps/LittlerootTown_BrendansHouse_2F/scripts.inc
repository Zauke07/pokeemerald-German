.set LOCALID_RIVAL, 1

LittlerootTown_BrendansHouse_2F_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_BrendansHouse_2F_OnTransition
    map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_BrendansHouse_2F_OnWarp
    .byte 0

LittlerootTown_BrendansHouse_2F_OnTransition:
    call_if_lt VAR_LITTLEROOT_RIVAL_STATE, 2, LittlerootTown_BrendansHouse_2F_EventScript_CheckSetReadyToMeetBrendan
    call_if_ge VAR_LITTLEROOT_RIVAL_STATE, 3, LittlerootTown_BrendansHouse_2F_EventScript_CheckShouldUpdateBrendanPos
    call_if_eq VAR_LITTLEROOT_INTRO_STATE, 4, PlayersHouse_2F_EventScript_BlockStairsUntilClockIsSet
    call SecretBase_EventScript_SetDecorationFlags
    setvar VAR_SECRET_BASE_INITIALIZED, 0
    end

LittlerootTown_BrendansHouse_2F_EventScript_CheckShouldUpdateBrendanPos::
    goto_if_set FLAG_MET_RIVAL_LILYCOVE, LittlerootTown_BrendansHouse_2F_EventScript_TryUpdateBrendanPos
    goto_if_ge VAR_BIRCH_LAB_STATE, 2, LittlerootTown_BrendansHouse_2F_EventScript_Ret
    goto LittlerootTown_BrendansHouse_2F_EventScript_TryUpdateBrendanPos

LittlerootTown_BrendansHouse_2F_EventScript_TryUpdateBrendanPos::
    getplayerstyle
    goto_if_eq VAR_RESULT, STYLE_BRENDAN, LittlerootTown_BrendansHouse_2F_EventScript_Ret
    goto_if_eq VAR_RESULT, STYLE_MAY, LittlerootTown_BrendansHouse_2F_EventScript_Ret
    goto_if_eq VAR_RESULT, STYLE_RED, LittlerootTown_BrendansHouse_2F_EventScript_Ret
    goto_if_eq VAR_RESULT, STYLE_LEAF, LittlerootTown_BrendansHouse_2F_EventScript_Ret
    goto_if_eq VAR_RESULT, STYLE_ETHAN, LittlerootTown_BrendansHouse_2F_EventScript_Ret
    goto_if_eq VAR_RESULT, STYLE_LYRA, LittlerootTown_BrendansHouse_2F_EventScript_Ret
    goto_if_eq VAR_RESULT, STYLE_LUCAS, LittlerootTown_BrendansHouse_2F_EventScript_Ret
    goto_if_eq VAR_RESULT, STYLE_DAWN, LittlerootTown_BrendansHouse_2F_EventScript_Ret
    goto_if_eq VAR_RESULT, STYLE_HILBERT, LittlerootTown_BrendansHouse_2F_EventScript_Ret
    goto_if_eq VAR_RESULT, STYLE_HILDA, LittlerootTown_BrendansHouse_2F_EventScript_Ret
    goto_if_eq VAR_RESULT, STYLE_NATE, LittlerootTown_BrendansHouse_2F_EventScript_Ret
    goto_if_eq VAR_RESULT, STYLE_ROSA, LittlerootTown_BrendansHouse_2F_EventScript_Ret
    goto_if_eq VAR_RESULT, STYLE_CALEM, LittlerootTown_BrendansHouse_2F_EventScript_Ret
    goto_if_eq VAR_RESULT, STYLE_SERENA, LittlerootTown_BrendansHouse_2F_EventScript_Ret
    goto_if_eq VAR_RESULT, STYLE_ELIO, LittlerootTown_BrendansHouse_2F_EventScript_Ret
    goto_if_eq VAR_RESULT, STYLE_SELENE, LittlerootTown_BrendansHouse_2F_EventScript_Ret
    goto_if_eq VAR_RESULT, STYLE_VICTOR, LittlerootTown_BrendansHouse_2F_EventScript_Ret
    goto_if_eq VAR_RESULT, STYLE_GLORIA, LittlerootTown_BrendansHouse_2F_EventScript_Ret
    goto_if_eq VAR_RESULT, STYLE_FLORIAN, LittlerootTown_BrendansHouse_2F_EventScript_Ret
    goto_if_eq VAR_RESULT, STYLE_JULIANA, LittlerootTown_BrendansHouse_2F_EventScript_Ret

    @ Die Bedingung mit dem Pokedex-Upgrade bleibt unverändert
    goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2, LittlerootTown_MaysHouse_2F_EventScript_Ret

    setobjectxyperm LOCALID_RIVAL, 0, 2
    setobjectmovementtype LOCALID_RIVAL, MOVEMENT_TYPE_FACE_UP
    return

LittlerootTown_BrendansHouse_2F_EventScript_Ret::
    return

LittlerootTown_BrendansHouse_2F_EventScript_CheckSetReadyToMeetBrendan::
    
    goto_if_eq VAR_RESULT, STYLE_BRENDAN, LittlerootTown_BrendansHouse_2F_EventScript_SetReadyToMeetBrendan
    goto_if_eq VAR_RESULT, STYLE_MAY, LittlerootTown_BrendansHouse_2F_EventScript_SetReadyToMeetBrendan
    goto_if_eq VAR_RESULT, STYLE_RED, LittlerootTown_BrendansHouse_2F_EventScript_SetReadyToMeetBrendan
    goto_if_eq VAR_RESULT, STYLE_LEAF, LittlerootTown_BrendansHouse_2F_EventScript_SetReadyToMeetBrendan
    goto_if_eq VAR_RESULT, STYLE_ETHAN, LittlerootTown_BrendansHouse_2F_EventScript_SetReadyToMeetBrendan
    goto_if_eq VAR_RESULT, STYLE_LYRA, LittlerootTown_BrendansHouse_2F_EventScript_SetReadyToMeetBrendan
    goto_if_eq VAR_RESULT, STYLE_LUCAS, LittlerootTown_BrendansHouse_2F_EventScript_SetReadyToMeetBrendan
    goto_if_eq VAR_RESULT, STYLE_DAWN, LittlerootTown_BrendansHouse_2F_EventScript_SetReadyToMeetBrendan
    goto_if_eq VAR_RESULT, STYLE_HILBERT, LittlerootTown_BrendansHouse_2F_EventScript_SetReadyToMeetBrendan
    goto_if_eq VAR_RESULT, STYLE_HILDA, LittlerootTown_BrendansHouse_2F_EventScript_SetReadyToMeetBrendan
    goto_if_eq VAR_RESULT, STYLE_NATE, LittlerootTown_BrendansHouse_2F_EventScript_SetReadyToMeetBrendan
    goto_if_eq VAR_RESULT, STYLE_ROSA, LittlerootTown_BrendansHouse_2F_EventScript_SetReadyToMeetBrendan
    goto_if_eq VAR_RESULT, STYLE_CALEM, LittlerootTown_BrendansHouse_2F_EventScript_SetReadyToMeetBrendan
    goto_if_eq VAR_RESULT, STYLE_SERENA, LittlerootTown_BrendansHouse_2F_EventScript_SetReadyToMeetBrendan
    goto_if_eq VAR_RESULT, STYLE_ELIO, LittlerootTown_BrendansHouse_2F_EventScript_SetReadyToMeetBrendan
    goto_if_eq VAR_RESULT, STYLE_SELENE, LittlerootTown_BrendansHouse_2F_EventScript_SetReadyToMeetBrendan
    goto_if_eq VAR_RESULT, STYLE_VICTOR, LittlerootTown_BrendansHouse_2F_EventScript_SetReadyToMeetBrendan
    goto_if_eq VAR_RESULT, STYLE_GLORIA, LittlerootTown_BrendansHouse_2F_EventScript_SetReadyToMeetBrendan
    goto_if_eq VAR_RESULT, STYLE_FLORIAN, LittlerootTown_BrendansHouse_2F_EventScript_SetReadyToMeetBrendan
    goto_if_eq VAR_RESULT, STYLE_JULIANA, LittlerootTown_BrendansHouse_2F_EventScript_SetReadyToMeetBrendan
    return

LittlerootTown_BrendansHouse_2F_EventScript_SetReadyToMeetBrendan::
    setvar VAR_LITTLEROOT_RIVAL_STATE, 2
    return

LittlerootTown_BrendansHouse_2F_OnWarp:
    map_script_2 VAR_SECRET_BASE_INITIALIZED, 0, LittlerootTown_BrendansHouse_2F_EventScript_CheckInitDecor
    .2byte 0

LittlerootTown_BrendansHouse_2F_EventScript_CheckInitDecor::
    
    goto_if_eq VAR_RESULT, STYLE_BRENDAN, SecretBase_EventScript_InitDecorations
    goto_if_eq VAR_RESULT, STYLE_MAY, SecretBase_EventScript_InitDecorations
    goto_if_eq VAR_RESULT, STYLE_RED, SecretBase_EventScript_InitDecorations
    goto_if_eq VAR_RESULT, STYLE_LEAF, SecretBase_EventScript_InitDecorations
    goto_if_eq VAR_RESULT, STYLE_ETHAN, SecretBase_EventScript_InitDecorations
    goto_if_eq VAR_RESULT, STYLE_LYRA, SecretBase_EventScript_InitDecorations
    goto_if_eq VAR_RESULT, STYLE_LUCAS, SecretBase_EventScript_InitDecorations
    goto_if_eq VAR_RESULT, STYLE_DAWN, SecretBase_EventScript_InitDecorations
    goto_if_eq VAR_RESULT, STYLE_HILBERT, SecretBase_EventScript_InitDecorations
    goto_if_eq VAR_RESULT, STYLE_HILDA, SecretBase_EventScript_InitDecorations
    goto_if_eq VAR_RESULT, STYLE_NATE, SecretBase_EventScript_InitDecorations
    goto_if_eq VAR_RESULT, STYLE_ROSA, SecretBase_EventScript_InitDecorations
    goto_if_eq VAR_RESULT, STYLE_CALEM, SecretBase_EventScript_InitDecorations
    goto_if_eq VAR_RESULT, STYLE_SERENA, SecretBase_EventScript_InitDecorations
    goto_if_eq VAR_RESULT, STYLE_ELIO, SecretBase_EventScript_InitDecorations
    goto_if_eq VAR_RESULT, STYLE_SELENE, SecretBase_EventScript_InitDecorations
    goto_if_eq VAR_RESULT, STYLE_VICTOR, SecretBase_EventScript_InitDecorations
    goto_if_eq VAR_RESULT, STYLE_GLORIA, SecretBase_EventScript_InitDecorations
    goto_if_eq VAR_RESULT, STYLE_FLORIAN, SecretBase_EventScript_InitDecorations
    goto_if_eq VAR_RESULT, STYLE_JULIANA, SecretBase_EventScript_InitDecorations
    end

LittlerootTown_BrendansHouse_2F_EventScript_RivalsPokeBall::
    lockall
    goto_if_eq VAR_LITTLEROOT_RIVAL_STATE, 2, LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendan
    msgbox RivalsHouse_2F_Text_ItsRivalsPokeBall, MSGBOX_DEFAULT
    releaseall
    end

LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendan::
    delay 10
    addobject LOCALID_RIVAL
    applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanEnters
    waitmovement 0
    playse SE_PIN
    applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
    waitmovement 0
    applymovement LOCALID_RIVAL, Common_Movement_Delay48
    waitmovement 0
    delay 10
    playbgm MUS_ENCOUNTER_BRENDAN, TRUE
    call_if_eq VAR_FACING, DIR_NORTH, LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanNorth
    call_if_eq VAR_FACING, DIR_SOUTH, LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanSouth
    call_if_eq VAR_FACING, DIR_WEST, LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanWest
    call_if_eq VAR_FACING, DIR_EAST, LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanEast
    setvar VAR_LITTLEROOT_RIVAL_STATE, 3
    setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL
    clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
    setvar VAR_LITTLEROOT_TOWN_STATE, 1
    savebgm MUS_DUMMY
    fadedefaultbgm
    releaseall
    end

LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanNorth::
    applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerNorth
    waitmovement 0
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
    waitmovement 0
    msgbox RivalsHouse_2F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
    closemessage
    applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanNorth
    applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCNorth
    waitmovement 0
    return

LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanSouth::
    applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerSouth
    waitmovement 0
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
    waitmovement 0
    msgbox RivalsHouse_2F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
    closemessage
    applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanSouth
    applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCSouth
    waitmovement 0
    return

LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanWest::
    applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerWest
    waitmovement 0
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
    waitmovement 0
    msgbox RivalsHouse_2F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
    closemessage
    applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanWest
    applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCWest
    waitmovement 0
    return

LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanEast::
    applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerEast
    waitmovement 0
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
    waitmovement 0
    msgbox RivalsHouse_2F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
    closemessage
    applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCEast
    waitmovement 0
    return

LittlerootTown_BrendansHouse_2F_Movement_BrendanEnters:
    walk_down
    walk_down
    walk_in_place_faster_left
    step_end

LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerNorth:
    walk_left
    walk_left
    walk_down
    walk_down
    walk_left
    step_end

LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCNorth:
    walk_up
    walk_up
    walk_up
    walk_left
    walk_left
    walk_left
    walk_left
    walk_in_place_faster_up
    step_end

LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanNorth:
    delay_16
    walk_in_place_faster_up
    delay_16
    delay_16
    delay_16
    delay_16
    walk_in_place_faster_left
    step_end

LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerSouth:
    walk_left
    walk_left
    walk_left
    step_end

LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCSouth:
    walk_up
    walk_left
    walk_left
    walk_left
    walk_left
    walk_in_place_faster_up
    step_end

LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanSouth:
    delay_16
    walk_in_place_faster_up
    delay_16
    delay_16
    walk_in_place_faster_left
    step_end

LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerWest:
    walk_left
    walk_left
    walk_down
    walk_in_place_faster_left
    step_end

LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCWest:
    walk_up
    walk_up
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_in_place_faster_up
    step_end

LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanWest:
    delay_8
    delay_16
    walk_in_place_faster_up
    delay_16
    delay_16
    walk_in_place_faster_left
    step_end

LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerEast:
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_in_place_faster_down
    step_end

LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCEast:
    walk_up
    walk_left
    walk_left
    walk_in_place_faster_up
    step_end

@ Unused, the player is already facing this direction so its unneeded
LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanEast:
    delay_16
    delay_16
    walk_in_place_faster_left
    step_end

LittlerootTown_BrendansHouse_2F_EventScript_PC::
    lockall
    
    goto_if_eq VAR_RESULT, STYLE_BRENDAN, LittlerootTown_BrendansHouse_2F_EventScript_CheckPlayersPC
    goto_if_eq VAR_RESULT, STYLE_RED, LittlerootTown_BrendansHouse_2F_EventScript_CheckPlayersPC
    goto_if_eq VAR_RESULT, STYLE_ETHAN, LittlerootTown_BrendansHouse_2F_EventScript_CheckPlayersPC
    goto_if_eq VAR_RESULT, STYLE_LUCAS, LittlerootTown_BrendansHouse_2F_EventScript_CheckPlayersPC
    goto_if_eq VAR_RESULT, STYLE_HILBERT, LittlerootTown_BrendansHouse_2F_EventScript_CheckPlayersPC
    goto_if_eq VAR_RESULT, STYLE_NATE, LittlerootTown_BrendansHouse_2F_EventScript_CheckPlayersPC
    goto_if_eq VAR_RESULT, STYLE_CALEM, LittlerootTown_BrendansHouse_2F_EventScript_CheckPlayersPC
    goto_if_eq VAR_RESULT, STYLE_ELIO, LittlerootTown_BrendansHouse_2F_EventScript_CheckPlayersPC
    goto_if_eq VAR_RESULT, STYLE_VICTOR, LittlerootTown_BrendansHouse_2F_EventScript_CheckPlayersPC
    goto_if_eq VAR_RESULT, STYLE_FLORIAN, LittlerootTown_BrendansHouse_2F_EventScript_CheckPlayersPC

    goto_if_eq VAR_RESULT, STYLE_MAY, LittlerootTown_BrendansHouse_2F_EventScript_CheckRivalsPC
    goto_if_eq VAR_RESULT, STYLE_LEAF, LittlerootTown_BrendansHouse_2F_EventScript_CheckRivalsPC
    goto_if_eq VAR_RESULT, STYLE_LYRA, LittlerootTown_BrendansHouse_2F_EventScript_CheckRivalsPC
    goto_if_eq VAR_RESULT, STYLE_DAWN, LittlerootTown_BrendansHouse_2F_EventScript_CheckRivalsPC
    goto_if_eq VAR_RESULT, STYLE_HILDA, LittlerootTown_BrendansHouse_2F_EventScript_CheckRivalsPC
    goto_if_eq VAR_RESULT, STYLE_ROSA, LittlerootTown_BrendansHouse_2F_EventScript_CheckRivalsPC
    goto_if_eq VAR_RESULT, STYLE_SERENA, LittlerootTown_BrendansHouse_2F_EventScript_CheckRivalsPC
    goto_if_eq VAR_RESULT, STYLE_SELENE, LittlerootTown_BrendansHouse_2F_EventScript_CheckRivalsPC
    goto_if_eq VAR_RESULT, STYLE_GLORIA, LittlerootTown_BrendansHouse_2F_EventScript_CheckRivalsPC
    goto_if_eq VAR_RESULT, STYLE_JULIANA, LittlerootTown_BrendansHouse_2F_EventScript_CheckRivalsPC
    end

LittlerootTown_BrendansHouse_2F_EventScript_CheckPlayersPC::
    setvar VAR_0x8004, PC_LOCATION_BRENDANS_HOUSE
    special DoPCTurnOnEffect
    playse SE_PC_ON
    msgbox gText_PlayerHouseBootPC, MSGBOX_DEFAULT
    special BedroomPC
    waitstate
    releaseall
    end

LittlerootTown_BrendansHouse_2F_EventScript_TurnOffPlayerPC::
    setvar VAR_0x8004, PC_LOCATION_BRENDANS_HOUSE
    playse SE_PC_OFF
    special DoPCTurnOffEffect
    releaseall
    end

LittlerootTown_BrendansHouse_2F_EventScript_CheckRivalsPC::
    msgbox gText_PokemonTrainerSchoolEmail, MSGBOX_DEFAULT
    releaseall
    end

PlayersHouse_2F_EventScript_Notebook::
    msgbox PlayersHouse_2F_Text_Notebook, MSGBOX_SIGN
    end

PlayersHouse_2F_EventScript_GameCube::
    msgbox PlayersHouse_2F_Text_ItsAGameCube, MSGBOX_SIGN
    end

PlayersHouse_2F_Text_ClockIsStopped:
    .string "Die Uhr ist stehen geblieben…\p"
    .string "Stelle sie besser ein und ziehe sie auf.$"

PlayersHouse_2F_Text_HowDoYouLikeYourRoom:
    .string "MOM: {PLAYER}, wie gefällt dir dein\n"
    .string "neues Zimmer?\p"
    .string "Gut! Alles ist wunderbar aufgeräumt!\p"
    .string "Auch im Erdgeschoss ist alles\n"
    .string "komplett eingerichtet.\p"
    .string "POKéMON-Umzugshelfer sind so\n"
    .string "praktisch.\p"
    .string "Oh, du solltest prüfen, ob dein Schreib-\n"
    .string "tisch vollständig eingeräumt ist!$"

PlayersHouse_2F_Text_Notebook:
    .string "{PLAYER} schlägt das Notizbuch auf.\p"
    .string "REGEL NR. 1 FÜR ABENTEURER\n"
    .string "Öffne das MENÜ mit START.\p"
    .string "REGEL NR. 2 FÜR ABENTEURER\n"
    .string "Speichere den Fortschritt mit SICHERN.\p"
    .string "Die übrigen Seiten sind leer.$"

Common_Text_LookCloserAtMap:
    .string "{PLAYER} schaut sich die Karte der\n"
    .string "HOENN-Region genauer an.$"

PlayersHouse_2F_Text_ItsAGameCube:
    .string "Das ist ein Nintendo GameCube.\p"
    .string "Ein Game Boy Advance ist angeschlossen\n"
    .string "und dient als Controller.$"
