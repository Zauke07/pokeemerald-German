.set LOCALID_CAPT_STERN, 4
.set LOCALID_SS_TIDAL, 5
.set LOCALID_GRUNT, 6
.set LOCALID_ARCHIE, 7
.set LOCALID_SUBMARINE, 8

SlateportCity_Harbor_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_Harbor_OnTransition
	.byte 0

SlateportCity_Harbor_OnTransition:
	setescapewarp MAP_SLATEPORT_CITY, 28, 13
	setvar VAR_TEMP_1, 0
	call_if_eq VAR_SLATEPORT_HARBOR_STATE, 1, SlateportCity_Harbor_EventScript_ReadyAquaEscapeScene
	call_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_ShowSSTidal
	end

SlateportCity_Harbor_EventScript_ShowSSTidal::
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_SS_TIDAL
	return

SlateportCity_Harbor_EventScript_ReadyAquaEscapeScene::
	savebgm MUS_ENCOUNTER_AQUA
	setobjectxyperm LOCALID_CAPT_STERN, 12, 13
	setobjectmovementtype LOCALID_CAPT_STERN, MOVEMENT_TYPE_FACE_LEFT
	setflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_PATRONS
	return

SlateportCity_Harbor_EventScript_AquaEscapeTrigger0::
	lockall
	setvar VAR_0x8008, 0
	goto SlateportCity_Harbor_EventScript_AquaEscapeScene
	end

SlateportCity_Harbor_EventScript_AquaEscapeTrigger1::
	lockall
	setvar VAR_0x8008, 1
	goto SlateportCity_Harbor_EventScript_AquaEscapeScene
	end

SlateportCity_Harbor_EventScript_AquaEscapeTrigger2::
	lockall
	setvar VAR_0x8008, 2
	goto SlateportCity_Harbor_EventScript_AquaEscapeScene
	end

SlateportCity_Harbor_EventScript_AquaEscapeTrigger3::
	lockall
	setvar VAR_0x8008, 3
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Harbor_Movement_PlayerWalkUp
	waitmovement 0
	goto SlateportCity_Harbor_EventScript_AquaEscapeScene
	end

SlateportCity_Harbor_EventScript_AquaEscapeScene::
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	applymovement LOCALID_GRUNT, Common_Movement_WalkInPlaceFasterDown
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_Harbor_Text_ArchieYouAgainHideoutInLilycove, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, SlateportCity_Harbor_Movement_AquaBoardSub
	applymovement LOCALID_ARCHIE, SlateportCity_Harbor_Movement_AquaBoardSub
	applymovement LOCALID_SUBMARINE, SlateportCity_Harbor_Movement_SubmarineExit
	waitmovement 0
	removeobject LOCALID_GRUNT
	removeobject LOCALID_ARCHIE
	removeobject LOCALID_SUBMARINE
	setvar VAR_SLATEPORT_HARBOR_STATE, 2
	setflag FLAG_MET_TEAM_AQUA_HARBOR
	setflag FLAG_HIDE_LILYCOVE_MOTEL_SCOTT
	call_if_eq VAR_0x8008, 0, SlateportCity_Harbor_EventScript_SternApproachPlayer0
	call_if_eq VAR_0x8008, 1, SlateportCity_Harbor_EventScript_SternApproachPlayer1
	call_if_eq VAR_0x8008, 2, SlateportCity_Harbor_EventScript_SternApproachPlayer
	call_if_eq VAR_0x8008, 3, SlateportCity_Harbor_EventScript_SternApproachPlayer
	msgbox SlateportCity_Harbor_Text_CaptSternWhyStealMySubmarine, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_HIDE_AQUA_HIDEOUT_1F_GRUNT_1_BLOCKING_ENTRANCE
	setflag FLAG_HIDE_AQUA_HIDEOUT_1F_GRUNT_2_BLOCKING_ENTRANCE
	copyobjectxytoperm LOCALID_CAPT_STERN
	setobjectmovementtype LOCALID_CAPT_STERN, MOVEMENT_TYPE_FACE_RIGHT
	releaseall
	end

SlateportCity_Harbor_EventScript_SternApproachPlayer0::
	applymovement LOCALID_CAPT_STERN, SlateportCity_Harbor_Movement_SternApproachPlayer0
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

SlateportCity_Harbor_EventScript_SternApproachPlayer1::
	applymovement LOCALID_CAPT_STERN, SlateportCity_Harbor_Movement_SternApproachPlayer1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

SlateportCity_Harbor_EventScript_SternApproachPlayer::
	applymovement LOCALID_CAPT_STERN, SlateportCity_Harbor_Movement_SternApproachPlayer
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

SlateportCity_Harbor_Movement_AquaBoardSub:
	delay_16
	delay_16
	jump_up
	set_invisible
	step_end

@ Unused, Archie instead shares above identical movement script with Grunt
SlateportCity_Harbor_Movement_ArchieBoardSub:
	delay_16
	delay_16
	jump_up
	set_invisible
	step_end

SlateportCity_Harbor_Movement_SubmarineExit:
	delay_16
	delay_16
	delay_16
	delay_16
	walk_right
	walk_right
	walk_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

SlateportCity_Harbor_Movement_SternApproachPlayer0:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

SlateportCity_Harbor_Movement_SternApproachPlayer1:
	walk_left
	walk_left
	walk_up
	walk_left
	step_end

SlateportCity_Harbor_Movement_SternApproachPlayer:
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_Harbor_Movement_PlayerWalkUp:
	walk_up
	step_end

SlateportCity_Harbor_EventScript_FerryAttendant::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_AskForTicket
	msgbox SlateportCity_Harbor_Text_FerryServiceUnavailable, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_AskForTicket::
	msgbox SlateportCity_Harbor_Text_MayISeeYourTicket, MSGBOX_DEFAULT
	message SlateportCity_Harbor_Text_FlashedTicketWhereTo
	waitmessage
	goto SlateportCity_Harbor_EventScript_ChooseDestination
	end

SlateportCity_Harbor_EventScript_ChooseDestination::
	goto_if_set FLAG_MET_SCOTT_ON_SS_TIDAL, SlateportCity_Harbor_EventScript_ChooseDestinationWithBattleFrontier
	multichoicedefault 18, 8, MULTI_SSTIDAL_SLATEPORT_NO_BF, 2, FALSE
	switch VAR_RESULT
	case 0, SlateportCity_Harbor_EventScript_Lilycove
	case 1, SlateportCity_Harbor_EventScript_CancelDestinationSelect
	case MULTI_B_PRESSED, SlateportCity_Harbor_EventScript_CancelDestinationSelect
	end

SlateportCity_Harbor_EventScript_ChooseDestinationWithBattleFrontier::
	multichoicedefault 17, 6, MULTI_SSTIDAL_SLATEPORT_WITH_BF, 2, FALSE
	switch VAR_RESULT
	case 0, SlateportCity_Harbor_EventScript_Lilycove
	case 1, SlateportCity_Harbor_EventScript_BattleFrontier
	case 2, SlateportCity_Harbor_EventScript_CancelDestinationSelect
	case MULTI_B_PRESSED, SlateportCity_Harbor_EventScript_CancelDestinationSelect
	end

@ Unused. Should be impossible for player to reach Ferry without having received SS Tidal ticket
SlateportCity_Harbor_EventScript_NoTicket::
	msgbox SlateportCity_Harbor_Text_YouMustHaveTicket, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_Lilycove::
	msgbox SlateportCity_Harbor_Text_LilycoveItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_Harbor_EventScript_ChooseNewDestination
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_BOARD_SLATEPORT
	call SlateportCity_Harbor_EventScript_BoardFerry
	warp MAP_SS_TIDAL_CORRIDOR, 1, 10
	waitstate
	release
	end

SlateportCity_Harbor_EventScript_BattleFrontier::
	msgbox SlateportCity_Harbor_Text_BattleFrontierItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_Harbor_EventScript_ChooseNewDestination
	call SlateportCity_Harbor_EventScript_BoardFerry
	warp MAP_BATTLE_FRONTIER_OUTSIDE_WEST, 19, 67
	waitstate
	release
	end

SlateportCity_Harbor_EventScript_ChooseNewDestination::
	message SlateportCity_Harbor_Text_WhereWouldYouLikeToGo
	waitmessage
	goto SlateportCity_Harbor_EventScript_ChooseDestination
	end

SlateportCity_Harbor_EventScript_BoardFerry::
	msgbox SlateportCity_Harbor_Text_PleaseBoardFerry, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 30
	hideobjectat VAR_LAST_TALKED, MAP_SLATEPORT_CITY_HARBOR
	call_if_eq VAR_FACING, DIR_NORTH, SlateportCity_Harbor_EventScript_BoardFerryNorth
	call_if_eq VAR_FACING, DIR_EAST, SlateportCity_Harbor_EventScript_BoardFerryEast
	delay 30
	hideobjectat OBJ_EVENT_ID_PLAYER, 0
	setvar VAR_0x8004, LOCALID_SS_TIDAL
	call Common_EventScript_FerryDepart
	return

SlateportCity_Harbor_EventScript_CancelDestinationSelect::
	msgbox SlateportCity_Harbor_Text_SailAnotherTime, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_BoardFerryEast::
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Harbor_Movement_BoardFerryEast
	waitmovement 0
	return

SlateportCity_Harbor_EventScript_BoardFerryNorth::
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Harbor_Movement_BoardFerryNorth
	waitmovement 0
	return

SlateportCity_Harbor_Movement_BoardFerryEast:
	walk_right
	walk_in_place_faster_up
	step_end

SlateportCity_Harbor_Movement_BoardFerryNorth:
	walk_up
	step_end

SlateportCity_Harbor_EventScript_Sailor::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_SailorNoAbnormalWeather
	setvar VAR_0x8004, 0
	call_if_set FLAG_DEFEATED_KYOGRE, SlateportCity_Harbor_EventScript_CountDefeatedLegendary
	call_if_set FLAG_DEFEATED_GROUDON, SlateportCity_Harbor_EventScript_CountDefeatedLegendary
	goto_if_eq VAR_0x8004, 2, SlateportCity_Harbor_EventScript_SailorNoAbnormalWeather  @ Defeated both
	msgbox SlateportCity_Harbor_Text_AbnormalWeather, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_SailorNoAbnormalWeather::
	msgbox SlateportCity_Harbor_Text_LoveToGoDeepUnderwaterSomeday, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_CountDefeatedLegendary::
	addvar VAR_0x8004, 1
	return

SlateportCity_Harbor_EventScript_FatMan::
	msgbox SlateportCity_Harbor_Text_SubTooSmallForMe, MSGBOX_NPC
	end

SlateportCity_Harbor_EventScript_CaptStern::
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, SlateportCity_Harbor_EventScript_CaptSternFerryOrScannerComment
	goto_if_set FLAG_EVIL_TEAM_ESCAPED_STERN_SPOKE, SlateportCity_Harbor_EventScript_NeedDive
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, SlateportCity_Harbor_EventScript_TeamAquaLeftNeedDive
	goto_if_eq VAR_SLATEPORT_HARBOR_STATE, 2, SlateportCity_Harbor_EventScript_WhyStealSubmarine
	msgbox SlateportCity_Harbor_Text_SameThugsTriedToRobAtMuseum, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_Harbor_EventScript_WhyStealSubmarine::
	msgbox SlateportCity_Harbor_Text_CaptSternWhyStealMySubmarine, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_TeamAquaLeftNeedDive::
	setflag FLAG_EVIL_TEAM_ESCAPED_STERN_SPOKE
	msgbox SlateportCity_Harbor_Text_TeamAquaLeftNeedDive, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_NeedDive::
	msgbox SlateportCity_Harbor_Text_NeedDiveToCatchSub, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_CaptSternFerryOrScannerComment::
	goto_if_eq VAR_TEMP_1, 1, SlateportCity_Harbor_EventScript_TradedScanner
	checkitem ITEM_SCANNER
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_Harbor_EventScript_AskToTradeScanner
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_FerryFinished
	msgbox SlateportCity_Harbor_Text_WontBeLongBeforeWeFinishFerry, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_FerryFinished::
	msgbox SlateportCity_Harbor_Text_FinishedMakingFerry, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_AskToTradeScanner::
	message SlateportCity_Harbor_Text_WouldYouTradeScanner
	waitmessage
	goto SlateportCity_Harbor_EventScript_ChooseScannerTrade
	end

SlateportCity_Harbor_EventScript_ChooseScannerTrade::
	multichoice 0, 0, MULTI_STERN_DEEPSEA, FALSE
	switch VAR_RESULT
	case 0, SlateportCity_Harbor_EventScript_DeepSeaTooth
	case 1, SlateportCity_Harbor_EventScript_DeepSeaScale
	case 2, SlateportCity_Harbor_EventScript_DeclineTrade
	case MULTI_B_PRESSED, SlateportCity_Harbor_EventScript_DeclineTrade
	end

SlateportCity_Harbor_EventScript_DeepSeaTooth::
	msgbox SlateportCity_Harbor_Text_TradeForDeepSeaTooth, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_Harbor_EventScript_ChooseDifferentTrade
	giveitem ITEM_DEEP_SEA_TOOTH
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	removeitem ITEM_SCANNER
	msgbox SlateportCity_Harbor_Text_HandedScannerToStern, MSGBOX_DEFAULT
	setflag FLAG_EXCHANGED_SCANNER
	goto SlateportCity_Harbor_EventScript_TradedScanner
	end

SlateportCity_Harbor_EventScript_DeepSeaScale::
	msgbox SlateportCity_Harbor_Text_TradeForDeepSeaScale, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_Harbor_EventScript_ChooseDifferentTrade
	giveitem ITEM_DEEP_SEA_SCALE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	removeitem ITEM_SCANNER
	msgbox SlateportCity_Harbor_Text_HandedScannerToStern, MSGBOX_DEFAULT
	setflag FLAG_EXCHANGED_SCANNER
	goto SlateportCity_Harbor_EventScript_TradedScanner
	end

SlateportCity_Harbor_EventScript_DeclineTrade::
	msgbox SlateportCity_Harbor_Text_IfYouWantToTradeLetMeKnow, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_ChooseDifferentTrade::
	message SlateportCity_Harbor_Text_WhichOneDoYouWant
	waitmessage
	goto SlateportCity_Harbor_EventScript_ChooseScannerTrade
	end

SlateportCity_Harbor_EventScript_TradedScanner::
	setvar VAR_TEMP_1, 1
	msgbox SlateportCity_Harbor_Text_ThisWillHelpResearch, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_Text_FerryServiceUnavailable:
	.string "Verzeihung?\n"
	.string "Du suchst nach einem Schiff?\p"
	.string "Oh, das tut mir Leid, aber die Fähre\n"
	.string "steht momentan nicht zur Verfügung…$"

SlateportCity_Harbor_Text_MayISeeYourTicket:
	.string "Hallo! Möchtest du mit der Fähre\n"
	.string "fahren? Zeigst du mir bitte dein\l"
	.string "TICKET?$"

SlateportCity_Harbor_Text_YouMustHaveTicket:
	.string "{PLAYER} hat kein TICKET…\p"
	.string "Das tut mir schrecklich Leid.\p"
	.string "Nur mit einem TICKET kannst du mit der\n"
	.string "Fähre fahren.$"

SlateportCity_Harbor_Text_FlashedTicketWhereTo:
	.string "{PLAYER} zückt das TICKET.\p"
	.string "Perfekt! Damit kannst du an Bord!\p"
	.string "Und wo soll die Reise hingehen?$"

SlateportCity_Harbor_Text_SailAnotherTime:
	.string "Bitte komm später noch einmal wieder!$"

SlateportCity_Harbor_Text_LilycoveItIs:
	.string "Nach SEEGRASULB CITY?$"

SlateportCity_Harbor_Text_BattleFrontierItIs:
	.string "Zur KAMPFZONE?$"

SlateportCity_Harbor_Text_PleaseBoardFerry:
	.string "Bitte komm an Bord. Wir legen bald ab.$"

SlateportCity_Harbor_Text_WhereWouldYouLikeToGo:
	.string "Und wo soll die Reise hingehen?$"

SlateportCity_Harbor_Text_LoveToGoDeepUnderwaterSomeday:
	.string "Eine Reise zum Meeresboden…\n"
	.string "Ich frage mich, wie es dort wohl ist?\p"
	.string "Eines Tages möchte ich auch einmal so\n"
	.string "tief unter Wasser reisen.$"

SlateportCity_Harbor_Text_AbnormalWeather:
	.string "Um eine sichere Schiffsreise zu\n"
	.string "gewährleisten, müssen wir stets auf\l"
	.string "das Wetter achten.\p"
	.string "Apropos Wetter: Ein Typ vom KLIMA-\n"
	.string "INSTITUT hat mir etwas Interessantes\l"
	.string "erzählt.\p"
	.string "Er sagte, dass im ganzen Land das\n"
	.string "Wetter verrückt spielt!\p"
	.string "Du solltest mal zum KLIMA-INSTITUT\n"
	.string "gehen und dich umhören.$"

SlateportCity_Harbor_Text_SubTooSmallForMe:
	.string "Ich wäre gerne mit KAPT. BRIGG auf die\n"
	.string "Expedition zum Meeresboden gegangen.\p"
	.string "Aber das U-Boot ist zu klein für mich.\p"
	.string "Ich könnte mich ja reinquetschen, aber\n"
	.string "dann hätte der KAPITÄN keinen Platz\l"
	.string "mehr…$"

SlateportCity_Harbor_Text_SameThugsTriedToRobAtMuseum:
	.string "KAPT. BRIGG: Diese Schlägertypen…\p"
	.string "Das sind die gleichen Typen, die\n"
	.string "versucht haben, die DEVON-WAREN aus\l"
	.string "dem MUSEUM zu stehlen.$"

SlateportCity_Harbor_Text_ArchieYouAgainHideoutInLilycove:
	.string "ADRIAN: Oh?\n"
	.string "Nicht du schon wieder… Stöhn…\p"
	.string "Du bist ganz schön hartnäckig, uns\n"
	.string "bis hierher zu folgen, das muss ich\l"
	.string "schon sagen.\p"
	.string "Und nun…\n"
	.string "Niemand kann uns stoppen! Niemand!!!\p"
	.string "Oder willst du uns etwa in unser VER-\n"
	.string "STECK in SEEGRASULB CITY folgen?\p"
	.string "Ahahahahaha…$"

SlateportCity_Harbor_Text_CaptSternWhyStealMySubmarine:
	.string "KAPT. BRIGG: Warum…\p"
	.string "Warum sollte TEAM AQUA mein TIEF-\n"
	.string "SEE-FORSCHUNGSBOOT 1 stehlen wollen?\p"
	.string "Sie können doch nicht hinter dem\n"
	.string "schlafenden POKéMON am Meeresgrund\l"
	.string "her sein…\p"
	.string "Selbst wenn ich sie verfolgen würde…\n"
	.string "Ich hätte keine Chance gegen sie…$"

SlateportCity_Harbor_Text_TeamAquaLeftNeedDive:
	.string "KAPT. BRIGG: Oh, {PLAYER}{KUN}…\p"
	.string "Okay… Du konntest TEAM AQUA nicht\n"
	.string "aufhalten…\p"
	.string "Oh, nein, mach dir bitte keine Vorwürfe!\n"
	.string "Die Schuld liegt nicht bei dir.\p"
	.string "Ein U-Boot zu verfolgen und aufzu-\n"
	.string "halten ist für die meisten Menschen\l"
	.string "unmöglich.\p"
	.string "Du benötigst ein POKéMON, das weiß, wie\n"
	.string "man TAUCHER ausführt…\p"
	.string "Vielleicht, wenn du dich nach\n"
	.string "MOOSBACH CITY begibst…\p"
	.string "Dort trifft man auf viele Taucher.\n"
	.string "Vielleicht kann dir einer das\l"
	.string "beibringen…$"

SlateportCity_Harbor_Text_NeedDiveToCatchSub:
	.string "KAPT. BRIGG: Ein U-Boot einzuholen und\n"
	.string "aufzuhalten… Das ist unmöglich.\p"
	.string "Du benötigst ein POKéMON, das weiß, wie\n"
	.string "man TAUCHER ausführt…\p"
	.string "Vielleicht, wenn du dich nach\n"
	.string "MOOSBACH CITY begibst…\p"
	.string "Dort trifft man auf viele Taucher, \n"
	.string "vielleicht kann dir einer das bei-\l"
	.string "bringen…$"

SlateportCity_Harbor_Text_WontBeLongBeforeWeFinishFerry:
	.string "KAPT. BRIGG: Oh, ja.\n"
	.string "MR. BRACK kam in unsere WERFT.\p"
	.string "Nun dauert es nicht mehr lange, bis wir\n"
	.string "unsere Fähre fertig stellen!$"

SlateportCity_Harbor_Text_FinishedMakingFerry:
	.string "KAPT. BRIGG: {PLAYER}{KUN}!\p"
	.string "Wir haben die Fähre MS TIDE endlich\n"
	.string "fertig gestellt.\p"
	.string "Ohne die Hilfe deines Freundes MR.\n"
	.string "BRACK hätten wir das nicht geschafft.\p"
	.string "Bitte nimm an einer kurzen Fahrt teil!$"

SlateportCity_Harbor_Text_WouldYouTradeScanner:
	.string "KAPT. BRIGG: Oh?\n"
	.string "{PLAYER}{KUN}, das Item, das du da hast…\p"
	.string "Das ist ein SCANNER! Der würde uns\n"
	.string "sicher bei unseren Forschungen helfen.\p"
	.string "{PLAYER}{KUN}, würdest du ihn gegen etwas\n"
	.string "anderes eintauschen?\p"
	.string "Zum Beispiel gegen einen ABYSSZAHN\n"
	.string "oder eine ABYSSPLATTE?$"

SlateportCity_Harbor_Text_IfYouWantToTradeLetMeKnow:
	.string "KAPT. BRIGG: Bist du sicher? Aber damit\n"
	.string "kannst du doch nichts anfangen…\p"
	.string "Also gut. Wenn du aber den SCANNER doch\n"
	.string "noch gegen etwas anderes tauschen\l"
	.string "willst, dann lass es mich wissen!$"

SlateportCity_Harbor_Text_TradeForDeepSeaTooth:
	.string "KAPT. BRIGG: Du möchtest den\n"
	.string "ABYSSZAHN dafür haben?$"

SlateportCity_Harbor_Text_TradeForDeepSeaScale:
	.string "KAPT. BRIGG: Du möchtest die\n"
	.string "ABYSSPLATTE dafür haben?$"

SlateportCity_Harbor_Text_WhichOneDoYouWant:
	.string "KAPT. BRIGG: Was hättest du gerne?$"

SlateportCity_Harbor_Text_HandedScannerToStern:
	.string "{PLAYER} gibt KAPT. BRIGG den SCANNER.$"

SlateportCity_Harbor_Text_ThisWillHelpResearch:
	.string "KAPT. BRIGG: Danke, {PLAYER}{KUN}!\n"
	.string "Das wird unsere Forschungen weiter-\l"
	.string "bringen!$"
