.set LOCALID_RIVAL, 16
.set LOCALID_RIVAL_ON_BIKE, 25
.set LOCALID_SCOTT, 43

Route119_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route119_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_OnTransition
	.byte 0

Route119_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Route119_EventScript_TryRemoveKecleon
	end

Route119_EventScript_TryRemoveKecleon::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

Route119_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	call Common_EventScript_SetupRivalOnBikeGfxId
	call_if_eq VAR_WEATHER_INSTITUTE_STATE, 1, Route119_EventScript_MoveInstituteWorkersDownstairs
	special SetRoute119Weather
	end

Route119_EventScript_MoveInstituteWorkersDownstairs::
	setflag FLAG_HIDE_WEATHER_INSTITUTE_2F_WORKERS
	clearflag FLAG_HIDE_WEATHER_INSTITUTE_1F_WORKERS
	setvar VAR_WEATHER_INSTITUTE_STATE, 2
	return

Route119_EventScript_RivalTrigger1::
	setvar VAR_TEMP_1, 1
	goto Route119_EventScript_RivalEncounter
	end

Route119_EventScript_RivalTrigger2::
	setvar VAR_TEMP_1, 2
	goto Route119_EventScript_RivalEncounter
	end

Route119_EventScript_RivalEncounter::
    lockall
    addobject LOCALID_RIVAL_ON_BIKE
    call Common_EventScript_SetupRivalMusic
    delay 65
    call_if_eq VAR_TEMP_1, 1, Route119_EventScript_RivalEnter1
    call_if_eq VAR_TEMP_1, 2, Route119_EventScript_RivalEnter2
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
    waitmovement 0
    delay 30
    call_if_eq VAR_TEMP_1, 1, Route119_EventScript_SetRivalPos1
    call_if_eq VAR_TEMP_1, 2, Route119_EventScript_SetRivalPos2
    removeobject LOCALID_RIVAL_ON_BIKE
    addobject LOCALID_RIVAL
    delay 30
    getplayerstyle
    goto_if_eq VAR_RESULT, STYLE_BRENDAN, Route119_EventScript_BattleMay
    goto_if_eq VAR_RESULT, STYLE_MAY, Route119_EventScript_BattleBrendan
    goto_if_eq VAR_RESULT, STYLE_RED, Route119_EventScript_BattleMay
    goto_if_eq VAR_RESULT, STYLE_LEAF, Route119_EventScript_BattleBrendan
    goto_if_eq VAR_RESULT, STYLE_ETHAN, Route119_EventScript_BattleMay
    goto_if_eq VAR_RESULT, STYLE_LYRA, Route119_EventScript_BattleBrendan
    goto_if_eq VAR_RESULT, STYLE_LUCAS, Route119_EventScript_BattleMay
    goto_if_eq VAR_RESULT, STYLE_DAWN, Route119_EventScript_BattleBrendan
    goto_if_eq VAR_RESULT, STYLE_HILBERT, Route119_EventScript_BattleMay
    goto_if_eq VAR_RESULT, STYLE_HILDA, Route119_EventScript_BattleBrendan
    goto_if_eq VAR_RESULT, STYLE_NATE, Route119_EventScript_BattleMay
    goto_if_eq VAR_RESULT, STYLE_ROSA, Route119_EventScript_BattleBrendan
    goto_if_eq VAR_RESULT, STYLE_CALEM, Route119_EventScript_BattleMay
    goto_if_eq VAR_RESULT, STYLE_SERENA, Route119_EventScript_BattleBrendan
    goto_if_eq VAR_RESULT, STYLE_ELIO, Route119_EventScript_BattleMay
    goto_if_eq VAR_RESULT, STYLE_SELENE, Route119_EventScript_BattleBrendan
    goto_if_eq VAR_RESULT, STYLE_VICTOR, Route119_EventScript_BattleMay
    goto_if_eq VAR_RESULT, STYLE_GLORIA, Route119_EventScript_BattleBrendan
    goto_if_eq VAR_RESULT, STYLE_FLORIAN, Route119_EventScript_BattleMay
    goto_if_eq VAR_RESULT, STYLE_JULIANA, Route119_EventScript_BattleBrendan
    releaseall
    end

Route119_EventScript_BattleMay::
	msgbox Route119_Text_MayIntro, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_BattleMayTreecko
	case 1, Route119_EventScript_BattleMayTorchic
	case 2, Route119_EventScript_BattleMayMudkip
	end

Route119_EventScript_BattleMayTreecko::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_TREECKO, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_BattleMayTorchic::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_TORCHIC, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_BattleMayMudkip::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_MUDKIP, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_DefeatedMay::
	msgbox Route119_Text_MayPresentForYou, MSGBOX_DEFAULT
	call Route119_EventScript_GiveFlyHM
	msgbox Route119_Text_MayExplainFly, MSGBOX_DEFAULT
	goto Route119_EventScript_RivalExitScottArrive
	end

Route119_EventScript_BattleBrendan::
	msgbox Route119_Text_BrendanIntro, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_BattleBrendanTreecko
	case 1, Route119_EventScript_BattleBrendanTorchic
	case 2, Route119_EventScript_BattleBrendanMudkip
	end

Route119_EventScript_BattleBrendanTreecko::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_TREECKO, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_BattleBrendanTorchic::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_TORCHIC, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_BattleBrendanMudkip::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_MUDKIP, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_DefeatedBrendan::
	msgbox Route119_Text_BrendanIllGiveYouThis, MSGBOX_DEFAULT
	call Route119_EventScript_GiveFlyHM
	msgbox Route119_Text_BrendanExplainFly, MSGBOX_DEFAULT
	goto Route119_EventScript_RivalExitScottArrive
	end

Route119_EventScript_GiveFlyHM::
	giveitem ITEM_HM_FLY
	setflag FLAG_RECEIVED_HM_FLY
	return

Route119_EventScript_RivalExitScottArrive::
	closemessage
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_SetRivalPos1
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_SetRivalPos2
	removeobject LOCALID_RIVAL
	addobject LOCALID_RIVAL_ON_BIKE
	delay 30
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_RivalExit1
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_RivalExit2
	removeobject LOCALID_RIVAL_ON_BIKE
	setvar VAR_ROUTE119_STATE, 1
	savebgm MUS_DUMMY
	fadedefaultbgm
	delay 60
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_SetScottPos1
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_SetScottPos2
	addobject LOCALID_SCOTT
	applymovement LOCALID_SCOTT, Route119_Movement_ScottEnter
	waitmovement 0
	addvar VAR_SCOTT_STATE, 1
	msgbox Route119_Text_ScottWayToGoBeSeeingYou, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_ScottExit1
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_ScottExit2
	removeobject LOCALID_SCOTT
	releaseall
	end

Route119_EventScript_SetScottPos1::
	setobjectxyperm LOCALID_SCOTT, 27, 25
	return

Route119_EventScript_SetScottPos2::
	setobjectxyperm LOCALID_SCOTT, 28, 25
	return

Route119_EventScript_ScottExit1::
	applymovement LOCALID_SCOTT, Route119_Movement_ScottExit1
	waitmovement 0
	return

Route119_EventScript_ScottExit2::
	applymovement LOCALID_SCOTT, Route119_Movement_ScottExit2
	waitmovement 0
	return

Route119_EventScript_RivalEnter1::
	applymovement LOCALID_RIVAL_ON_BIKE, Route119_Movement_RivalEnter1
	waitmovement 0
	return

Route119_EventScript_RivalEnter2::
	applymovement LOCALID_RIVAL_ON_BIKE, Route119_Movement_RivalEnter2
	waitmovement 0
	return

Route119_EventScript_RivalExit1::
	applymovement OBJ_EVENT_ID_PLAYER, Route119_Movement_PlayerWatchRivalExit1
	applymovement LOCALID_RIVAL_ON_BIKE, Route119_Movement_RivalExit1
	waitmovement 0
	return

Route119_EventScript_RivalExit2::
	applymovement OBJ_EVENT_ID_PLAYER, Route119_Movement_PlayerWatchRivalExit2
	applymovement LOCALID_RIVAL_ON_BIKE, Route119_Movement_RivalExit2
	waitmovement 0
	return

Route119_EventScript_SetRivalPos1::
	setobjectxyperm LOCALID_RIVAL, 25, 32
	setobjectxyperm LOCALID_RIVAL_ON_BIKE, 25, 32
	return

Route119_EventScript_SetRivalPos2::
	setobjectxyperm LOCALID_RIVAL, 26, 32
	setobjectxyperm LOCALID_RIVAL_ON_BIKE, 26, 32
	return

Route119_Movement_PlayerWatchRivalExit1:
	delay_16
	walk_in_place_faster_right
	delay_8
	walk_in_place_faster_up
	step_end

Route119_Movement_PlayerWatchRivalExit2:
	delay_16
	walk_in_place_faster_left
	delay_8
	walk_in_place_faster_up
	step_end

Route119_Movement_RivalEnter1:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	step_end

Route119_Movement_RivalEnter2:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	step_end

Route119_Movement_RivalExit1:
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Route119_Movement_RivalExit2:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Route119_Movement_ScottEnter:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	step_end

Route119_Movement_ScottExit1:
	walk_up
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route119_Movement_ScottExit2:
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route119_EventScript_CyclingTriathleteM::
	msgbox Route119_Text_TallGrassSnaresBikeTires, MSGBOX_NPC
	end

Route119_EventScript_RouteSignFortree::
	msgbox Route119_Text_RouteSignFortree, MSGBOX_SIGN
	end

Route119_EventScript_WeatherInstituteSign::
	msgbox Route119_Text_WeatherInstitute, MSGBOX_SIGN
	end

Route119_EventScript_Brent::
	trainerbattle_single TRAINER_BRENT, Route119_Text_BrentIntro, Route119_Text_BrentDefeat
	msgbox Route119_Text_BrentPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Donald::
	trainerbattle_single TRAINER_DONALD, Route119_Text_DonaldIntro, Route119_Text_DonaldDefeat
	msgbox Route119_Text_DonaldPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Taylor::
	trainerbattle_single TRAINER_TAYLOR, Route119_Text_TaylorIntro, Route119_Text_TaylorDefeat
	msgbox Route119_Text_TaylorPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Doug::
	trainerbattle_single TRAINER_DOUG, Route119_Text_DougIntro, Route119_Text_DougDefeat
	msgbox Route119_Text_DougPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Greg::
	trainerbattle_single TRAINER_GREG, Route119_Text_GregIntro, Route119_Text_GregDefeat
	msgbox Route119_Text_GregPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Kent::
	trainerbattle_single TRAINER_KENT, Route119_Text_KentIntro, Route119_Text_KentDefeat
	msgbox Route119_Text_KentPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Jackson::
	trainerbattle_single TRAINER_JACKSON_1, Route119_Text_JacksonIntro, Route119_Text_JacksonDefeat, Route119_EventScript_RegisterJackson
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route119_EventScript_RematchJackson
	msgbox Route119_Text_JacksonPostBattle, MSGBOX_DEFAULT
	release
	end

Route119_EventScript_RegisterJackson::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route119_Text_JacksonRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JACKSON_1
	release
	end

Route119_EventScript_RematchJackson::
	trainerbattle_rematch TRAINER_JACKSON_1, Route119_Text_JacksonRematchIntro, Route119_Text_JacksonRematchDefeat
	msgbox Route119_Text_JacksonPostRematch, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Catherine::
	trainerbattle_single TRAINER_CATHERINE_1, Route119_Text_CatherineIntro, Route119_Text_CatherineDefeat, Route119_EventScript_RegisterCatherine
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route119_EventScript_RematchCatherine
	msgbox Route119_Text_CatherinePostBattle, MSGBOX_DEFAULT
	release
	end

Route119_EventScript_RegisterCatherine::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route119_Text_CatherineRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CATHERINE_1
	release
	end

Route119_EventScript_RematchCatherine::
	trainerbattle_rematch TRAINER_CATHERINE_1, Route119_Text_CatherineRematchIntro, Route119_Text_CatherineRematchDefeat
	msgbox Route119_Text_CatherinePostRematch, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Hugh::
	trainerbattle_single TRAINER_HUGH, Route119_Text_HughIntro, Route119_Text_HughDefeat
	msgbox Route119_Text_HughPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Phil::
	trainerbattle_single TRAINER_PHIL, Route119_Text_PhilIntro, Route119_Text_PhilDefeat
	msgbox Route119_Text_PhilPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Yasu::
	trainerbattle_single TRAINER_YASU, Route119_Text_YasuIntro, Route119_Text_YasuDefeat
	msgbox Route119_Text_YasuPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Takashi::
	trainerbattle_single TRAINER_TAKASHI, Route119_Text_TakashiIntro, Route119_Text_TakashiDefeat
	msgbox Route119_Text_TakashiPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Hideo::
	trainerbattle_single TRAINER_HIDEO, Route119_Text_HideoIntro, Route119_Text_HideoDefeat
	msgbox Route119_Text_HideoPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Chris::
	trainerbattle_single TRAINER_CHRIS, Route119_Text_ChrisIntro, Route119_Text_ChrisDefeat
	msgbox Route119_Text_ChrisPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Fabian::
	trainerbattle_single TRAINER_FABIAN, Route119_Text_FabianIntro, Route119_Text_FabianDefeat
	msgbox Route119_Text_FabianPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Dayton::
	trainerbattle_single TRAINER_DAYTON, Route119_Text_DaytonIntro, Route119_Text_DaytonDefeat
	msgbox Route119_Text_DaytonPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Rachel::
	trainerbattle_single TRAINER_RACHEL, Route119_Text_RachelIntro, Route119_Text_RachelDefeat
	msgbox Route119_Text_RachelPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_BridgeAquaGrunt1::
	lock
	faceplayer
	msgbox Route119_Text_StayAwayFromWeatherInstitute, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route119_EventScript_BridgeAquaGrunt2::
	lock
	faceplayer
	msgbox Route119_Text_DontGoNearWeatherInstitute, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route119_EventScript_Boy1::
	msgbox Route119_Text_ThoughtFlyByCatchingBirdMons, MSGBOX_NPC
	end

Route119_EventScript_Boy2::
	msgbox Route119_Text_CanYourMonMakeSecretBase, MSGBOX_NPC
	end

Route119_EventScript_TrainerTipsDecoration::
	msgbox Route119_Text_TrainerTipsDecoration, MSGBOX_SIGN
	end

Route119_EventScript_ScottWonAtFortreeGymCall::
	lockall
	pokenavcall Route119_Text_ScottYouWonAtFortreeGym
	waitmessage
	clearflag FLAG_SCOTT_CALL_FORTREE_GYM
	addvar VAR_SCOTT_STATE, 1
	releaseall
	end

Route119_Text_MayIntro:
	.string "{RIVAL}: {PLAYER}{KUN}! Wo warst du?\n"
	.string "Ich habe dich schon gesucht!\p"
	.string "Wie stark bist du geworden?\n"
	.string "Lass mich das für dich herausfinden!\p"
	.string "Bereit? Du und deine Pokémon?\n"
	.string "Natürlich seid ihr das! Los!$"

Route119_Text_MayDefeat:
	.string "Achah!\n"
	.string "{PLAYER}{KUN}, du bist stark!\p"
	.string "Ich hatte schon befürchtet, du\n"
	.string "hättest im Training nachgelassen.$"

Route119_Text_MayPresentForYou:
	.string "{RIVAL}: Aber ich hätte mir absolut keine\n"
	.string "Sorgen zu machen brauchen! Weiter so!\p"
	.string "Und hier!\n"
	.string "Dies ist ein Geschenk für dich!$"

Route119_Text_MayExplainFly:
	.string "{RIVAL}: Setze FLIEGEN ein und deine\n"
	.string "Pokémon bringen dich an jeden Ort, an\l"
	.string "dem du schon einmal warst.\p"
	.string "Aber um FLIEGEN einsetzen zu können,\n"
	.string "brauchst du erst den ORDEN der ARENA\l"
	.string "von BAUMHAUSEN CITY.\l"
	.string "Vergiss das nicht!\p"
	.string "Du solltest mal nach WURZELHEIM\n"
	.string "FLIEGEN.\p"
	.string "Ich wette, deine Mutter macht sich\n"
	.string "schon Sorgen um dich, {PLAYER}{KUN}.\p"
	.string "Nun, wir treffen uns sicher bald wieder!$"

Route119_Text_BrendanIntro:
	.string "{RIVAL}: {PLAYER}! Hier schaust du dich\n"
	.string "also nach Pokémon um?\p"
	.string "Zeig mir, wie gut du geworden bist.\n"
	.string "Ich werde dich jetzt testen!\p"
	.string "Nun!\n"
	.string "Das ist ein Kampf, also kämpfen wir!$"

Route119_Text_BrendanDefeat:
	.string "Hmm…\n"
	.string "Du bist verdammt gut geworden.$"

Route119_Text_BrendanIllGiveYouThis:
	.string "{RIVAL}: Ich sage, du bist so gut, dass\n"
	.string "du überall nach Pokémon suchen kannst.\p"
	.string "Hier, das ist für dich.\n"
	.string "Probier es aus.$"

Route119_Text_BrendanExplainFly:
	.string "{RIVAL}: Setze es ein, und deine\n"
	.string "Pokémon FLIEGEN dich sofort an jeden\l"
	.string "Ort, an dem du schon einmal warst.\p"
	.string "Aber du brauchst den ORDEN der ARENA\n"
	.string "von BAUMHAUSEN CITY dafür.\p"
	.string "Nun ja, ich muss jetzt weiter. Bis bald.$"

Route119_Text_ScottWayToGoBeSeeingYou:
	.string "SCOTT: Hahahaha!\n"
	.string "Mach weiter so, {PLAYER}{KUN}!\p"
	.string "Ich bin gerade einem TRAINER begegnet,\n"
	.string "der auf einem FAHRRAD fuhr.\p"
	.string "Du hast den TRAINER besiegt, stimmt’s?\n"
	.string "Das war ihm anzumerken.\p"
	.string "Das Kind war richtig wütend und sein\n"
	.string "Gesicht war rot vor Zorn.\p"
	.string "Wir laufen uns wirklich oft über den\n"
	.string "Weg! Gehst du jetzt zur ARENA in\l"
	.string "BAUMHAUSEN CITY?\p"
	.string "Ich erwarte, dass du dich dort\n"
	.string "besonders anstrengst. Mach’s gut.$"

Route119_Text_ScottYouWonAtFortreeGym:
	.string "… … … … …\n"
	.string "…\l"
	.string "… … … … …\l"
	.string "Piep!\p"
	.string "SCOTT: Hi {PLAYER}{KUN}, ich bin’s!\p"
	.string "Ich wusste, dass du in der ARENA\n"
	.string "von BAUMHAUSEN gewinnen würdest.\p"
	.string "Deine Stärke…\n"
	.string "Vielleicht bist du wirklich der\l"
	.string "TRAINER, den ich die ganze Zeit\p"
	.string "suche. Ich bin dein Fan, vergiss\n"
	.string "das nicht. Ich werde dir zujubeln.\l"
	.string "Mach weiter so!\p"
	.string "… … … … …\n"
	.string "…\l"
	.string "… … … … …\l"
	.string "Klick!$"

Route119_Text_StayAwayFromWeatherInstitute:
	.string "Wir stehen hier Wache.\p"
	.string "Hey, du! Halt dich bloß von dem KLIMA-\n"
	.string "INSTITUT fern. Da ist es nicht sicher!$"

Route119_Text_DontGoNearWeatherInstitute:
	.string "Wache schieben ist langweilig.\p"
	.string "Hey, du! Komm nicht in die Nähe des\n"
	.string "KLIMA-INSTITUTs.$"

Route119_Text_ThoughtFlyByCatchingBirdMons:
	.string "Ich dachte, FLIEGEN könnte man, indem\n"
	.string "man viele VOGEL-Pokémon fängt, sie\p"
	.string "zusammenbindet und sich dann\n"
	.string "dranhängt.\p"
	.string "Aber es gibt tatsächlich eine VM, die\n"
	.string "FLIEGEN heißt!\p"
	.string "Wenn ich das doch nur eher gewusst\n"
	.string "hätte…$"

Route119_Text_TallGrassSnaresBikeTires:
	.string "Tse… So geht es nicht weiter…\p"
	.string "Das hohe Gras verfängt sich in den \n"
	.string "Speichen des RADs…$"

Route119_Text_CanYourMonMakeSecretBase:
	.string "Kann dein Pokémon GEHEIMPOWER an\n"
	.string "einem Berg von Gras einsetzen und eine\l"
	.string "GEHEIMBASIS einrichten?$"

Route119_Text_RouteSignFortree:
	.string "ROUTE 119\n"
	.string "{RIGHT_ARROW} BAUMHAUSEN CITY$"

Route119_Text_WeatherInstitute:
	.string "KLIMA-INSTITUT$"

Route119_Text_TrainerTipsDecoration:
	.string "TIPPS für TRAINER\p"
	.string "In der GEHEIMBASIS können bis zu 16\n"
	.string "Dekorationen und Möbel untergebracht\l"
	.string "werden.\p"
	.string "Nimm deine Lieblingsitems und richte dir\n"
	.string "deine GEHEIMBASIS ganz nach deinem\l"
	.string "Geschmack ein.$"

Route119_EventScript_Froxy::
    msgbox Route119_Text_Froxy, MSGBOX_NPC
    end

Route119_Text_Froxy:
	.string "Tipp:\p"
	.string "Auf dieser Route versteckt sich ein\n"
	.string "Starter aus der 6 Generation mit\l"
	.string "einer Spawnrate von 1%!\p"
	.string "Welches es ist, musst du selbst\n"
	.string "herausfinden :D !$"
