.set LOCALID_STEVEN, 19

Route118_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route118_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route118_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route118_OnFrame
	.byte 0

Route118_OnTransition:
	call GabbyAndTy_EventScript_UpdateLocation
	call_if_eq VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_HideMapNamePopup
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_118_EAST, AbnormalWeather_StartGroudonWeather
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_118_WEST, AbnormalWeather_StartGroudonWeather
	end

Route118_OnLoad:
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_118_EAST, AbnormalWeather_EventScript_PlaceTilesRoute118East
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_118_WEST, AbnormalWeather_EventScript_PlaceTilesRoute118West
	end

Route118_OnFrame:
	map_script_2 VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_EndEventAndCleanup_1
	.2byte 0

Route118_EventScript_GoodRodFisherman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_GOOD_ROD, Route118_EventScript_ReceivedGoodRod
	msgbox Route118_Text_YouAgreeGoodRodIsGood, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route118_EventScript_ReceiveGoodRod
	goto_if_eq VAR_RESULT, NO, Route118_EventScript_DeclineGoodRod
	end

Route118_EventScript_ReceiveGoodRod::
	msgbox Route118_Text_IdenticalMindsTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_GOOD_ROD
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_GOOD_ROD
	msgbox Route118_Text_TryYourLuckFishing, MSGBOX_DEFAULT
	release
	end

Route118_EventScript_DeclineGoodRod::
	msgbox Route118_Text_DontYouLikeToFish, MSGBOX_DEFAULT
	release
	end

Route118_EventScript_ReceivedGoodRod::
	msgbox Route118_Text_TryCatchingMonWithGoodRod, MSGBOX_DEFAULT
	release
	end

Route118_EventScript_Girl::
	msgbox Route118_Text_CanCrossRiversWithSurf, MSGBOX_NPC
	end

Route118_EventScript_RouteSignMauville::
	msgbox Route118_Text_RouteSignMauville, MSGBOX_SIGN
	end

Route118_EventScript_RouteSign119::
	msgbox Route118_Text_RouteSign119, MSGBOX_SIGN
	end

Route118_EventScript_StevenTrigger0::
	lockall
	setvar VAR_0x8008, 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_STEVEN, Route118_Movement_StevenApproachLedge0
	waitmovement 0
	goto Route118_EventScript_StevenTrigger
	end

Route118_EventScript_StevenTrigger1::
	lockall
	setvar VAR_0x8008, 1
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	goto Route118_EventScript_StevenTrigger
	end

Route118_EventScript_StevenTrigger2::
	lockall
	setvar VAR_0x8008, 2
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_STEVEN, Route118_Movement_StevenApproachLedge2
	waitmovement 0
	goto Route118_EventScript_StevenTrigger
	end

Route118_EventScript_StevenTrigger::
	playse SE_LEDGE
	applymovement LOCALID_STEVEN, Route118_Movement_StevenJumpLedge
	waitmovement 0
	delay 30
	msgbox Route118_Text_StevenQuestions, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, 0, Route118_EventScript_StevenExit0
	call_if_eq VAR_0x8008, 1, Route118_EventScript_StevenExit1
	call_if_eq VAR_0x8008, 2, Route118_EventScript_StevenExit2
	setvar VAR_ROUTE118_STATE, 1
	removeobject LOCALID_STEVEN
	releaseall
	end

Route118_EventScript_StevenExit0::
	applymovement OBJ_EVENT_ID_PLAYER, Route118_Movement_PlayerWatchStevenExit
	applymovement LOCALID_STEVEN, Route118_Movement_StevenExit0
	waitmovement 0
	return

Route118_EventScript_StevenExit1::
	applymovement OBJ_EVENT_ID_PLAYER, Route118_Movement_PlayerWatchStevenExit
	applymovement LOCALID_STEVEN, Route118_Movement_StevenExit1
	waitmovement 0
	return

Route118_EventScript_StevenExit2::
	applymovement OBJ_EVENT_ID_PLAYER, Route118_Movement_PlayerWatchStevenExit
	applymovement LOCALID_STEVEN, Route118_Movement_StevenExit2
	waitmovement 0
	return

Route118_Movement_PlayerWatchStevenExit:
	delay_16
	walk_in_place_faster_right
	step_end

Route118_Movement_StevenApproachLedge0:
	walk_left
	step_end

Route118_Movement_StevenApproachLedge2:
	walk_right
	step_end

Route118_Movement_StevenJumpLedge:
	jump_2_down
	delay_16
	walk_down
	step_end

Route118_Movement_StevenExit0:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route118_Movement_StevenExit1:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route118_Movement_StevenExit2:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route118_EventScript_Rose::
	trainerbattle_single TRAINER_ROSE_1, Route118_Text_RoseIntro, Route118_Text_RoseDefeat, Route118_EventScript_RegisterRose
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route118_EventScript_RematchRose
	msgbox Route118_Text_RosePostBattle, MSGBOX_DEFAULT
	release
	end

Route118_EventScript_RegisterRose::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route118_Text_RoseRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ROSE_1
	release
	end

Route118_EventScript_RematchRose::
	trainerbattle_rematch TRAINER_ROSE_1, Route118_Text_RoseRematchIntro, Route118_Text_RoseRematchDefeat
	msgbox Route118_Text_RosePostRematch, MSGBOX_AUTOCLOSE
	end

Route118_EventScript_Barny::
	trainerbattle_single TRAINER_BARNY, Route118_Text_BarnyIntro, Route118_Text_BarnyDefeat
	msgbox Route118_Text_BarnyPostBattle, MSGBOX_AUTOCLOSE
	end

Route118_EventScript_Wade::
	trainerbattle_single TRAINER_WADE, Route118_Text_WadeIntro, Route118_Text_WadeDefeat
	msgbox Route118_Text_WadePostBattle, MSGBOX_AUTOCLOSE
	end

Route118_EventScript_Dalton::
	trainerbattle_single TRAINER_DALTON_1, Route118_Text_DaltonIntro, Route118_Text_DaltonDefeat, Route118_EventScript_RegisterDalton
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route118_EventScript_RematchDalton
	msgbox Route118_Text_DaltonPostBattle, MSGBOX_DEFAULT
	release
	end

Route118_EventScript_RegisterDalton::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route118_Text_DaltonRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_DALTON_1
	release
	end

Route118_EventScript_RematchDalton::
	trainerbattle_rematch TRAINER_DALTON_1, Route118_Text_DaltonRematchIntro, Route118_Text_DaltonRematchDefeat
	msgbox Route118_Text_DaltonPostRematch, MSGBOX_AUTOCLOSE
	end

Route118_EventScript_Perry::
	trainerbattle_single TRAINER_PERRY, Route118_Text_PerryIntro, Route118_Text_PerryDefeat
	msgbox Route118_Text_PerryPostBattle, MSGBOX_AUTOCLOSE
	end

Route118_EventScript_Chester::
	trainerbattle_single TRAINER_CHESTER, Route118_Text_ChesterIntro, Route118_Text_ChesterDefeat
	msgbox Route118_Text_ChesterPostBattle, MSGBOX_AUTOCLOSE
	end

Route118_EventScript_Deandre::
	trainerbattle_single TRAINER_DEANDRE, Route118_Text_DeandreIntro, Route118_Text_DeandreDefeat
	msgbox Route118_Text_DeandrePostBattle, MSGBOX_AUTOCLOSE
	end

Route118_Text_StevenQuestions:
	.string "TROY: Hi {PLAYER}{KUN}!\p"
	.string "Ich bin’s, TROY!\n"
	.string "Wir haben uns in der Höhle in der Nähe\l"
	.string "von FAUSTAUHAVEN getroffen.\p"
	.string "Hast du seitdem viele Pokémon\n"
	.string "gesehen?\p"
	.string "In dieser großen Welt gibt es viele\n"
	.string "verschiedene Arten von Pokémon.\p"
	.string "Wenn du nur deine Lieblings-\n"
	.string "Pokémon aufziehst, ist das völlig\l"
	.string "in Ordnung.\p"
	.string "Aber vielleicht findest du es ja\n"
	.string "auch spannender, unterschiedliche\l"
	.string "Pokémon aufzuziehen.\p"
	.string "Was denkst du als TRAINER darüber?\p"
	.string "Okay, das geht mich eigentlich\n"
	.string "gar nichts an.\p"
	.string "Nun, ich hoffe, wir sehen uns bald\n"
	.string "wieder.$"

Route118_Text_YouAgreeGoodRodIsGood:
	.string "Hmm!\n"
	.string "Eine PROFIANGEL ist wirklich gut!\p"
	.string "Meinst du nicht auch?$"

Route118_Text_IdenticalMindsTakeThis:
	.string "Hmm!\n"
	.string "Da sind wir ja der gleichen Meinung!\p"
	.string "Hmm!\n"
	.string "Ich schenke dir diese PROFIANGEL!$"

Route118_Text_TryYourLuckFishing:
	.string "Wo immer du Wasser findest, versuche\n"
	.string "dein Glück mit Angeln.$"

Route118_Text_DontYouLikeToFish:
	.string "Magst du keinen Fisch?$"

Route118_Text_TryCatchingMonWithGoodRod:
	.string "Versuche, alle möglichen Arten von\n"
	.string "Pokémon mit der PROFIANGEL zu fangen.$"

Route118_Text_CanCrossRiversWithSurf:
	.string "Auch wenn gerade kein Schiff in der\n"
	.string "Nähe ist, kannst du mit einem Pokémon,\l"
	.string "das SURFER kennt, das Meer überqueren.\p"
	.string "Auf Pokémon kann man sich immer\n"
	.string "verlassen!$"

Route118_Text_RouteSignMauville:
	.string "ROUTE 118\n"
	.string "{LEFT_ARROW} MALVENFROH CITY$"

Route118_Text_RouteSign119:
	.string "ROUTE 118\n"
	.string "{UP_ARROW} ROUTE 119$"

Route118_EventScript_Ottaro::
    msgbox Route118_Text_Ottaro, MSGBOX_NPC
    end

Route118_Text_Ottaro:
	.string "Tipp:\p"
	.string "Auf dieser Route versteckt sich ein\n"
	.string "Starter aus der 5 Generation mit\l"
	.string "einer Spawnrate von 1%!\p"
	.string "Welches es ist, musst du selbst\n"
	.string "herausfinden :D !$"
