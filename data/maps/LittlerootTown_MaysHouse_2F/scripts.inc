.set LOCALID_RIVAL, 1

LittlerootTown_MaysHouse_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_MaysHouse_2F_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_MaysHouse_2F_OnWarp
	.byte 0

LittlerootTown_MaysHouse_2F_OnTransition:
	call_if_lt VAR_LITTLEROOT_RIVAL_STATE, 2, LittlerootTown_MaysHouse_2F_EventScript_CheckSetReadyToMeetMay
	call_if_ge VAR_LITTLEROOT_RIVAL_STATE, 3, LittlerootTown_MaysHouse_2F_EventScript_CheckShouldUpdateMayPos
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 4, PlayersHouse_2F_EventScript_BlockStairsUntilClockIsSet
	call SecretBase_EventScript_SetDecorationFlags
	setvar VAR_SECRET_BASE_INITIALIZED, 0
	end

LittlerootTown_MaysHouse_2F_EventScript_CheckShouldUpdateMayPos::
	goto_if_set FLAG_MET_RIVAL_LILYCOVE, LittlerootTown_MaysHouse_2F_EventScript_TryUpdateMayPos
	goto_if_ge VAR_BIRCH_LAB_STATE, 2, LittlerootTown_MaysHouse_2F_EventScript_Ret
	goto LittlerootTown_MaysHouse_2F_EventScript_TryUpdateMayPos

LittlerootTown_MaysHouse_2F_EventScript_TryUpdateMayPos::
	getplayerstyle
	goto_if_eq VAR_RESULT, STYLE_MAY, LittlerootTown_MaysHouse_2F_EventScript_Ret
	goto_if_eq VAR_RESULT, STYLE_LEAF, LittlerootTown_MaysHouse_2F_EventScript_Ret
	goto_if_eq VAR_RESULT, STYLE_LYRA, LittlerootTown_MaysHouse_2F_EventScript_Ret
	goto_if_eq VAR_RESULT, STYLE_DAWN, LittlerootTown_MaysHouse_2F_EventScript_Ret
	goto_if_eq VAR_RESULT, STYLE_HILDA, LittlerootTown_MaysHouse_2F_EventScript_Ret
	goto_if_eq VAR_RESULT, STYLE_ROSA, LittlerootTown_MaysHouse_2F_EventScript_Ret
	goto_if_eq VAR_RESULT, STYLE_SERENA, LittlerootTown_MaysHouse_2F_EventScript_Ret
	goto_if_eq VAR_RESULT, STYLE_SELENE, LittlerootTown_MaysHouse_2F_EventScript_Ret
	goto_if_eq VAR_RESULT, STYLE_GLORIA, LittlerootTown_MaysHouse_2F_EventScript_Ret
	goto_if_eq VAR_RESULT, STYLE_JULIANA, LittlerootTown_MaysHouse_2F_EventScript_Ret
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2, LittlerootTown_MaysHouse_2F_EventScript_Ret
	setobjectxyperm LOCALID_RIVAL, 8, 2
	setobjectmovementtype LOCALID_RIVAL, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_MaysHouse_2F_EventScript_Ret::
	return

LittlerootTown_MaysHouse_2F_EventScript_CheckSetReadyToMeetMay::
	goto_if_eq VAR_RESULT, STYLE_BRENDAN, LittlerootTown_MaysHouse_2F_EventScript_SetReadyToMeetMay
	goto_if_eq VAR_RESULT, STYLE_RED, LittlerootTown_MaysHouse_2F_EventScript_SetReadyToMeetMay
	goto_if_eq VAR_RESULT, STYLE_ETHAN, LittlerootTown_MaysHouse_2F_EventScript_SetReadyToMeetMay
	goto_if_eq VAR_RESULT, STYLE_LUCAS, LittlerootTown_MaysHouse_2F_EventScript_SetReadyToMeetMay
	goto_if_eq VAR_RESULT, STYLE_HILBERT, LittlerootTown_MaysHouse_2F_EventScript_SetReadyToMeetMay
	goto_if_eq VAR_RESULT, STYLE_NATE, LittlerootTown_MaysHouse_2F_EventScript_SetReadyToMeetMay
	goto_if_eq VAR_RESULT, STYLE_CALEM, LittlerootTown_MaysHouse_2F_EventScript_SetReadyToMeetMay
	goto_if_eq VAR_RESULT, STYLE_ELIO, LittlerootTown_MaysHouse_2F_EventScript_SetReadyToMeetMay
	goto_if_eq VAR_RESULT, STYLE_VICTOR, LittlerootTown_MaysHouse_2F_EventScript_SetReadyToMeetMay
	goto_if_eq VAR_RESULT, STYLE_FLORIAN, LittlerootTown_MaysHouse_2F_EventScript_SetReadyToMeetMay
	return

LittlerootTown_MaysHouse_2F_EventScript_SetReadyToMeetMay::
	setvar VAR_LITTLEROOT_RIVAL_STATE, 2
	return

LittlerootTown_MaysHouse_2F_OnWarp:
	map_script_2 VAR_SECRET_BASE_INITIALIZED, 0, LittlerootTown_MaysHouse_2F_EventScript_CheckInitDecor
	.2byte 0

LittlerootTown_MaysHouse_2F_EventScript_CheckInitDecor::
	goto_if_eq VAR_RESULT, STYLE_MAY, SecretBase_EventScript_InitDecorations
	goto_if_eq VAR_RESULT, STYLE_LEAF, SecretBase_EventScript_InitDecorations
	goto_if_eq VAR_RESULT, STYLE_LYRA, SecretBase_EventScript_InitDecorations
	goto_if_eq VAR_RESULT, STYLE_DAWN, SecretBase_EventScript_InitDecorations
	goto_if_eq VAR_RESULT, STYLE_HILDA, SecretBase_EventScript_InitDecorations
	goto_if_eq VAR_RESULT, STYLE_ROSA, SecretBase_EventScript_InitDecorations
	goto_if_eq VAR_RESULT, STYLE_SERENA, SecretBase_EventScript_InitDecorations
	goto_if_eq VAR_RESULT, STYLE_SELENE, SecretBase_EventScript_InitDecorations
	goto_if_eq VAR_RESULT, STYLE_GLORIA, SecretBase_EventScript_InitDecorations
	goto_if_eq VAR_RESULT, STYLE_JULIANA, SecretBase_EventScript_InitDecorations
	end

LittlerootTown_MaysHouse_2F_EventScript_RivalsPokeBall::
	lockall
	goto_if_eq VAR_LITTLEROOT_RIVAL_STATE, 2, LittlerootTown_MaysHouse_2F_EventScript_MeetMay
	msgbox RivalsHouse_2F_Text_ItsRivalsPokeBall, MSGBOX_DEFAULT
	releaseall
	end

LittlerootTown_MaysHouse_2F_EventScript_MeetMay::
	delay 10
	addobject LOCALID_RIVAL
	applymovement LOCALID_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayEnters
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	delay 10
	playbgm MUS_ENCOUNTER_MAY, TRUE
	call_if_eq VAR_FACING, DIR_NORTH, LittlerootTown_MaysHouse_2F_EventScript_MeetMayNorth
	call_if_eq VAR_FACING, DIR_SOUTH, LittlerootTown_MaysHouse_2F_EventScript_MeetMaySouth
	call_if_eq VAR_FACING, DIR_WEST, LittlerootTown_MaysHouse_2F_EventScript_MeetMayWest
	call_if_eq VAR_FACING, DIR_EAST, LittlerootTown_MaysHouse_2F_EventScript_MeetMayEast
	setvar VAR_LITTLEROOT_RIVAL_STATE, 3
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_POKE_BALL
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
	setvar VAR_LITTLEROOT_TOWN_STATE, 1
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

LittlerootTown_MaysHouse_2F_EventScript_MeetMayNorth::
	applymovement LOCALID_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerNorth
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox RivalsHouse_2F_Text_MayWhoAreYou, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMayNorth
	applymovement LOCALID_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCNorth
	waitmovement 0
	return

LittlerootTown_MaysHouse_2F_EventScript_MeetMaySouth::
	applymovement LOCALID_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerSouth
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox RivalsHouse_2F_Text_MayWhoAreYou, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMaySouth
	applymovement LOCALID_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCSouth
	waitmovement 0
	return

LittlerootTown_MaysHouse_2F_EventScript_MeetMayWest::
	applymovement LOCALID_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerWest
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox RivalsHouse_2F_Text_MayWhoAreYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCWest
	waitmovement 0
	return

LittlerootTown_MaysHouse_2F_EventScript_MeetMayEast::
	applymovement LOCALID_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerEast
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox RivalsHouse_2F_Text_MayWhoAreYou, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMayEast
	applymovement LOCALID_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCEast
	waitmovement 0
	return

LittlerootTown_MaysHouse_2F_Movement_MayEnters:
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerNorth:
	walk_right
	walk_right
	walk_down
	walk_down
	walk_right
	step_end

LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCNorth:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMayNorth:
	delay_16
	walk_in_place_faster_up
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_right
	step_end

LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerSouth:
	walk_right
	walk_right
	walk_right
	step_end

LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCSouth:
	walk_up
	walk_in_place_faster_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMaySouth:
	delay_16
	walk_in_place_faster_up
	delay_16
	delay_16
	walk_in_place_faster_right
	step_end

LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerWest:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_down
	step_end

LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCWest:
	walk_up
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

@ Unused, the player is already facing this direction so its unneeded
LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMayWest:
	delay_16
	delay_16
	walk_in_place_faster_right
	step_end

LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerEast:
	walk_right
	walk_right
	walk_down
	walk_in_place_faster_right
	step_end

LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCEast:
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMayEast:
	delay_16
	walk_in_place_faster_up
	delay_16
	delay_16
	walk_in_place_faster_right
	step_end

RivalsHouse_2F_EventScript_Rival::
	lockall
	goto_if_set FLAG_MET_RIVAL_LILYCOVE, RivalsHouse_2F_EventScript_RivalPostLilycove
	goto_if_eq VAR_RESULT, STYLE_MAY, RivalsHouse_2F_EventScript_RivalFemale
	goto_if_eq VAR_RESULT, STYLE_LEAF, RivalsHouse_2F_EventScript_RivalFemale
	goto_if_eq VAR_RESULT, STYLE_LYRA, RivalsHouse_2F_EventScript_RivalFemale
	goto_if_eq VAR_RESULT, STYLE_DAWN, RivalsHouse_2F_EventScript_RivalFemale
	goto_if_eq VAR_RESULT, STYLE_HILDA, RivalsHouse_2F_EventScript_RivalFemale
	goto_if_eq VAR_RESULT, STYLE_ROSA, RivalsHouse_2F_EventScript_RivalFemale
	goto_if_eq VAR_RESULT, STYLE_SERENA, RivalsHouse_2F_EventScript_RivalFemale
	goto_if_eq VAR_RESULT, STYLE_SELENE, RivalsHouse_2F_EventScript_RivalFemale
	goto_if_eq VAR_RESULT, STYLE_GLORIA, RivalsHouse_2F_EventScript_RivalFemale
	goto_if_eq VAR_RESULT, STYLE_JULIANA, RivalsHouse_2F_EventScript_RivalFemale
	goto_if_eq VAR_RESULT, STYLE_BRENDAN, RivalsHouse_2F_EventScript_RivalMale
	goto_if_eq VAR_RESULT, STYLE_RED, RivalsHouse_2F_EventScript_RivalMale
	goto_if_eq VAR_RESULT, STYLE_ETHAN, RivalsHouse_2F_EventScript_RivalMale
	goto_if_eq VAR_RESULT, STYLE_LUCAS, RivalsHouse_2F_EventScript_RivalMale
	goto_if_eq VAR_RESULT, STYLE_HILBERT, RivalsHouse_2F_EventScript_RivalMale
	goto_if_eq VAR_RESULT, STYLE_NATE, RivalsHouse_2F_EventScript_RivalMale
	goto_if_eq VAR_RESULT, STYLE_CALEM, RivalsHouse_2F_EventScript_RivalMale
	goto_if_eq VAR_RESULT, STYLE_ELIO, RivalsHouse_2F_EventScript_RivalMale
	goto_if_eq VAR_RESULT, STYLE_VICTOR, RivalsHouse_2F_EventScript_RivalMale
	goto_if_eq VAR_RESULT, STYLE_FLORIAN, RivalsHouse_2F_EventScript_RivalMale
	end

RivalsHouse_2F_EventScript_RivalFemale::
	msgbox RivalsHouse_2F_Text_MayGettingReady, MSGBOX_DEFAULT
	releaseall
	end

RivalsHouse_2F_EventScript_RivalMale::
	msgbox RivalsHouse_2F_Text_BrendanGettingReady, MSGBOX_DEFAULT
	releaseall
	end

RivalsHouse_2F_EventScript_RivalPostLilycove::
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	call_if_eq VAR_RESULT, STYLE_MAY, RivalsHouse_2F_EventScript_RivalFemalePostLilycove
	call_if_eq VAR_RESULT, STYLE_LEAF, RivalsHouse_2F_EventScript_RivalFemalePostLilycove
	call_if_eq VAR_RESULT, STYLE_LYRA, RivalsHouse_2F_EventScript_RivalFemalePostLilycove
	call_if_eq VAR_RESULT, STYLE_DAWN, RivalsHouse_2F_EventScript_RivalFemalePostLilycove
	call_if_eq VAR_RESULT, STYLE_HILDA, RivalsHouse_2F_EventScript_RivalFemalePostLilycove
	call_if_eq VAR_RESULT, STYLE_ROSA, RivalsHouse_2F_EventScript_RivalFemalePostLilycove
	call_if_eq VAR_RESULT, STYLE_SERENA, RivalsHouse_2F_EventScript_RivalFemalePostLilycove
	call_if_eq VAR_RESULT, STYLE_SELENE, RivalsHouse_2F_EventScript_RivalFemalePostLilycove
	call_if_eq VAR_RESULT, STYLE_GLORIA, RivalsHouse_2F_EventScript_RivalFemalePostLilycove
	call_if_eq VAR_RESULT, STYLE_JULIANA, RivalsHouse_2F_EventScript_RivalFemalePostLilycove
	call_if_eq VAR_RESULT, STYLE_BRENDAN, RivalsHouse_2F_EventScript_RivalMalePostLilycove
	call_if_eq VAR_RESULT, STYLE_RED, RivalsHouse_2F_EventScript_RivalMalePostLilycove
	call_if_eq VAR_RESULT, STYLE_ETHAN, RivalsHouse_2F_EventScript_RivalMalePostLilycove
	call_if_eq VAR_RESULT, STYLE_LUCAS, RivalsHouse_2F_EventScript_RivalMalePostLilycove
	call_if_eq VAR_RESULT, STYLE_HILBERT, RivalsHouse_2F_EventScript_RivalMalePostLilycove
	call_if_eq VAR_RESULT, STYLE_NATE, RivalsHouse_2F_EventScript_RivalMalePostLilycove
	call_if_eq VAR_RESULT, STYLE_CALEM, RivalsHouse_2F_EventScript_RivalMalePostLilycove
	call_if_eq VAR_RESULT, STYLE_ELIO, RivalsHouse_2F_EventScript_RivalMalePostLilycove
	call_if_eq VAR_RESULT, STYLE_VICTOR, RivalsHouse_2F_EventScript_RivalMalePostLilycove
	call_if_eq VAR_RESULT, STYLE_FLORIAN, RivalsHouse_2F_EventScript_RivalMalePostLilycove
	setflag FLAG_MET_RIVAL_IN_HOUSE_AFTER_LILYCOVE
	releaseall
	end

RivalsHouse_2F_EventScript_RivalFemalePostLilycove::
	goto_if_set FLAG_MET_RIVAL_IN_HOUSE_AFTER_LILYCOVE, RivalsHouse_2F_EventScript_MayWhereShouldIGoNext
	msgbox RivalsHouse_2F_Text_MayJustCheckingMyPokedex, MSGBOX_DEFAULT
	return

RivalsHouse_2F_EventScript_RivalMalePostLilycove::
	goto_if_set FLAG_MET_RIVAL_IN_HOUSE_AFTER_LILYCOVE, RivalsHouse_2F_EventScript_BrendanWhereShouldIGoNext
	msgbox RivalsHouse_2F_Text_BrendanJustCheckingMyPokedex, MSGBOX_DEFAULT
	return

RivalsHouse_2F_EventScript_MayWhereShouldIGoNext::
	msgbox RivalsHouse_2F_Text_MayWhereShouldIGoNext, MSGBOX_DEFAULT
	return

RivalsHouse_2F_EventScript_BrendanWhereShouldIGoNext::
	msgbox RivalsHouse_2F_Text_BrendanWhereShouldIGoNext, MSGBOX_DEFAULT
	return

LittlerootTown_MaysHouse_2F_EventScript_PC::
	lockall
	goto_if_eq VAR_RESULT, STYLE_MAY, LittlerootTown_MaysHouse_2F_EventScript_CheckPlayersPC
	goto_if_eq VAR_RESULT, STYLE_LEAF, LittlerootTown_MaysHouse_2F_EventScript_CheckPlayersPC
	goto_if_eq VAR_RESULT, STYLE_LYRA, LittlerootTown_MaysHouse_2F_EventScript_CheckPlayersPC
	goto_if_eq VAR_RESULT, STYLE_DAWN, LittlerootTown_MaysHouse_2F_EventScript_CheckPlayersPC
	goto_if_eq VAR_RESULT, STYLE_HILDA, LittlerootTown_MaysHouse_2F_EventScript_CheckPlayersPC
	goto_if_eq VAR_RESULT, STYLE_ROSA, LittlerootTown_MaysHouse_2F_EventScript_CheckPlayersPC
	goto_if_eq VAR_RESULT, STYLE_SERENA, LittlerootTown_MaysHouse_2F_EventScript_CheckPlayersPC
	goto_if_eq VAR_RESULT, STYLE_SELENE, LittlerootTown_MaysHouse_2F_EventScript_CheckPlayersPC
	goto_if_eq VAR_RESULT, STYLE_GLORIA, LittlerootTown_MaysHouse_2F_EventScript_CheckPlayersPC
	goto_if_eq VAR_RESULT, STYLE_JULIANA, LittlerootTown_MaysHouse_2F_EventScript_CheckPlayersPC
	goto_if_eq VAR_RESULT, STYLE_BRENDAN, LittlerootTown_MaysHouse_2F_EventScript_CheckRivalsPC
	goto_if_eq VAR_RESULT, STYLE_RED, LittlerootTown_MaysHouse_2F_EventScript_CheckRivalsPC
	goto_if_eq VAR_RESULT, STYLE_ETHAN, LittlerootTown_MaysHouse_2F_EventScript_CheckRivalsPC
	goto_if_eq VAR_RESULT, STYLE_LUCAS, LittlerootTown_MaysHouse_2F_EventScript_CheckRivalsPC
	goto_if_eq VAR_RESULT, STYLE_HILBERT, LittlerootTown_MaysHouse_2F_EventScript_CheckRivalsPC
	goto_if_eq VAR_RESULT, STYLE_NATE, LittlerootTown_MaysHouse_2F_EventScript_CheckRivalsPC
	goto_if_eq VAR_RESULT, STYLE_CALEM, LittlerootTown_MaysHouse_2F_EventScript_CheckRivalsPC
	goto_if_eq VAR_RESULT, STYLE_ELIO, LittlerootTown_MaysHouse_2F_EventScript_CheckRivalsPC
	goto_if_eq VAR_RESULT, STYLE_VICTOR, LittlerootTown_MaysHouse_2F_EventScript_CheckRivalsPC
	goto_if_eq VAR_RESULT, STYLE_FLORIAN, LittlerootTown_MaysHouse_2F_EventScript_CheckRivalsPC
	end

LittlerootTown_MaysHouse_2F_EventScript_CheckRivalsPC::
	msgbox gText_PokemonTrainerSchoolEmail, MSGBOX_DEFAULT
	releaseall
	end

LittlerootTown_MaysHouse_2F_EventScript_CheckPlayersPC::
	setvar VAR_0x8004, PC_LOCATION_MAYS_HOUSE
	special DoPCTurnOnEffect
	playse SE_PC_ON
	msgbox gText_PlayerHouseBootPC, MSGBOX_DEFAULT
	special BedroomPC
	waitstate
	releaseall
	end

LittlerootTown_MaysHouse_2F_EventScript_TurnOffPlayerPC::
	setvar VAR_0x8004, PC_LOCATION_MAYS_HOUSE
	playse SE_PC_OFF
	special DoPCTurnOffEffect
	releaseall
	end

RivalsHouse_2F_Text_MayWhoAreYou:
	.string "Was?\n"
	.string "Wer… Wer bist du denn?\p"
	.string "… … … … … … … …\n"
	.string "… … … … … … … …\p"
	.string "Ach, du bist {PLAYER}{KUN}!\n"
	.string "Du bist heute hierher gezogen.\p"
	.string "Ähm… Ich bin {RIVAL}.\n"
	.string "Schön, dich kennen zu lernen.\p"
	.string "Ich… Ich habe diesen Traum…\n"
	.string "Mit POKéMON in der ganzen Welt\l"
	.string "Freundschaft zu schließen.\p"
	.string "Ich… Ich habe schon von dir gehört.\n"
	.string "Mein Vater, PROF. BIRK, hat mir von\l"
	.string "dir erzählt.\p"
	.string "Ich habe gehofft, dass du nett bist,\n"
	.string "{PLAYER}{KUN}, und wir Freunde werden.\p"
	.string "Ist das nicht albern? Ich… Ich habe\n"
	.string "dich doch gerade erst kennen gelernt.\p"
	.string "Hihihihi…\p"
	.string "Oh, nein! Das habe ich ja total\n"
	.string "vergessen!\p"
	.string "Ich sollte Vati doch helfen, ein paar\n"
	.string "wilde POKéMON zu fangen!\p"
	.string "{PLAYER}{KUN}, wir treffen uns später!$"

RivalsHouse_2F_Text_MayGettingReady:
	.string "POKéMON: Bei guter Gesundheit!\n"
	.string "Items: Verstaut. Fehlt noch… Was?$"

RivalsHouse_2F_Text_BrendanWhoAreYou:
	.string "Hey!\n"
	.string "Du…\p"
	.string "Wer bist du denn?\p"
	.string "Ach ja, du bist {PLAYER}, richtig?\n"
	.string "Du bist nebenan eingezogen, stimmt’s?\p"
	.string "Ich wusste nicht, dass du ein Mädchen\n"
	.string "bist.\p"
	.string "Vater, PROF. BIRK, hat mir erzählt, dass\n"
	.string "nebenan das Kind eines ARENALEITERs\p"
	.string "einzieht und irgendwie habe ich\n"
	.string "gedacht, du seiest ein Junge.\p"
	.string "Ich heiße übrigens {RIVAL}.\n"
	.string "Also: Hallo, Nachbarin!\p"
	.string "Was? {PLAYER}, du hast kein einziges\n"
	.string "POKéMON?\p"
	.string "Soll ich eines für dich fangen?\p"
	.string "Ach, Mist, das habe ich ganz vergessen…\p"
	.string "Ich muss meinem Vater helfen, einige\n"
	.string "wilde POKéMON zu fangen.\p"
	.string "Ein anderes Mal, okay?$"

RivalsHouse_2F_Text_BrendanGettingReady:
	.string "POKéMON: Bei guter Gesundheit!\n"
	.string "Items: Verstaut. Fehlt noch… Was?$"

RivalsHouse_2F_Text_ItsRivalsPokeBall:
	.string "Der POKéBALL gehört {RIVAL}!\n"
	.string "Lass ihn besser liegen!$"

RivalsHouse_2F_Text_MayJustCheckingMyPokedex:
	.string "{RIVAL}: {PLAYER}{KUN}!\p"
	.string "Ich prüfe gerade meinen POKéDEX.\p"
	.string "Es gibt eine Menge POKéMON, die ich\n"
	.string "gesehen, aber nicht gefangen habe.\p"
	.string "Und es gibt viele, von denen ich\n"
	.string "annehme, dass sie sich bald entwickeln.\p"
	.string "Jetzt überlege ich, wo ich hingehen\n"
	.string "soll, um weitere POKéMON zu fangen.$"

RivalsHouse_2F_Text_MayWhereShouldIGoNext:
	.string "{RIVAL}: Ich überlege, wo ich hingehen\n"
	.string "soll, um weitere POKéMON zu fangen.\p"
	.string "Wäre es nicht lustig, wenn wir uns dabei\n"
	.string "über den Weg laufen würden?$"

RivalsHouse_2F_Text_BrendanJustCheckingMyPokedex:
	.string "{RIVAL}: Hey, {PLAYER}!\p"
	.string "Ich prüfe gerade meinen POKéDEX.\p"
	.string "Es gibt noch viele POKéMON, die ich\n"
	.string "fangen muss, aber er sieht schon sehr\l"
	.string "gut aus.\p"
	.string "Immer wenn ich den POKéDEX betrachte,\n"
	.string "bekomme ich Lust zu reisen.$"

RivalsHouse_2F_Text_BrendanWhereShouldIGoNext:
	.string "{RIVAL}: Ich habe lange überlegt, wo ich\n"
	.string "hingehen soll, um weitere POKéMON\l"
	.string "zu fangen.\p"
	.string "Hey, {PLAYER}, wenn ich dich auf meiner\n"
	.string "Suche treffe, können wir ja einen\l"
	.string "POKéMON-Kampf austragen.$"
