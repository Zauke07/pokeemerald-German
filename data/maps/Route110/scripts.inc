.set LOCALID_CHALLENGE_BIKER, 21
.set LOCALID_RIVAL, 28
.set LOCALID_RIVAL_ON_BIKE, 29
.set LOCALID_BIRCH, 36

Route110_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route110_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route110_OnFrame
	.byte 0

Route110_OnResume:
	special UpdateCyclingRoadState
	end

Route110_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	call Common_EventScript_SetupRivalOnBikeGfxId
	call_if_eq VAR_CYCLING_CHALLENGE_STATE, 1, Route110_EventScript_SaveCyclingMusic
	end

Route110_EventScript_SaveCyclingMusic::
	savebgm MUS_CYCLING
	return

Route110_OnFrame:
	map_script_2 VAR_CYCLING_CHALLENGE_STATE, 1, Route110_EventScript_BeginCylcingRoadChallenge
	.2byte 0

Route110_EventScript_BeginCylcingRoadChallenge::
	special Special_BeginCyclingRoadChallenge
	setvar VAR_CYCLING_CHALLENGE_STATE, 2
	return

Route110_EventScript_AquaGrunt1::
	lock
	faceplayer
	msgbox Route110_Text_WeCantTalkAboutAquaActivities, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route110_EventScript_AquaGrunt2::
	lock
	faceplayer
	msgbox Route110_Text_KickUpARuckus, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route110_EventScript_AquaGrunt3::
	lock
	faceplayer
	msgbox Route110_Text_MyFirstJobInAqua, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route110_EventScript_AquaGrunt4::
	lock
	faceplayer
	msgbox Route110_Text_AquaActionsBringSmiles, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route110_EventScript_Boy1::
	msgbox Route110_Text_RideBikeAtFullSpeed, MSGBOX_NPC
	end

Route110_EventScript_CyclingGirl1::
	msgbox Route110_Text_HairStreamsBehindMe, MSGBOX_NPC
	end

Route110_EventScript_CyclingGuy1::
	msgbox Route110_Text_YouGotBikeFromRydel, MSGBOX_NPC
	end

Route110_EventScript_OldMan::
	msgbox Route110_Text_TwoRoads, MSGBOX_NPC
	end

Route110_EventScript_OldWoman::
	msgbox Route110_Text_WalkOnTheLowRoad, MSGBOX_NPC
	end

Route110_EventScript_CyclingGuy2::
	msgbox Route110_Text_BikeTechniques, MSGBOX_NPC
	end

Route110_EventScript_Boy2::
	msgbox Route110_Text_WhichShouldIChoose, MSGBOX_NPC
	end

Route110_EventScript_SlateportCitySign::
	msgbox Route110_Text_SlateportCitySign, MSGBOX_SIGN
	end

Route110_EventScript_CyclingRoadSign::
	msgbox Route110_Text_CyclingRoadSign, MSGBOX_SIGN
	end

Route110_EventScript_VandalizedSign::
	msgbox Route110_Text_AquaWasHere, MSGBOX_SIGN
	end

Route110_EventScript_Route103Sign::
	msgbox Route110_Text_Route103Sign, MSGBOX_SIGN
	end

Route110_EventScript_SeasideParkingSign::
	msgbox Route110_Text_SeasideParkingSign, MSGBOX_SIGN
	end

Route110_EventScript_MauvilleCitySign::
	msgbox Route110_Text_MauvilleCitySign, MSGBOX_SIGN
	end

Route110_EventScript_TrainerTipsPrlzSleep::
	msgbox Route110_Text_TrainerTipsPrlzSleep, MSGBOX_SIGN
	end

Route110_EventScript_TrainerTipsRegisterItems::
	msgbox Route110_Text_TrainerTipsRegisterItems, MSGBOX_SIGN
	end

Route110_EventScript_TrickHouseSign::
	msgbox Route110_Text_TrickHouseSign, MSGBOX_SIGN
	end

Route110_EventScript_CyclingRoadResultsSign::
	lockall
	specialvar VAR_RESULT, GetRecordedCyclingRoadResults
	goto_if_eq VAR_RESULT, FALSE, Route110_EventScript_NoRecordSet
	msgbox Route110_Text_BestRecord, MSGBOX_DEFAULT
	releaseall
	end

Route110_EventScript_NoRecordSet::
	msgbox Route110_Text_ThereIsNoRecord, MSGBOX_DEFAULT
	releaseall
	end

Route110_EventScript_ChallengeGuy::
	lock
	faceplayer
	specialvar VAR_RESULT, GetPlayerAvatarBike
	goto_if_eq VAR_RESULT, 1, Route110_EventScript_PlayerRidingAcroBike
	goto_if_eq VAR_CYCLING_CHALLENGE_STATE, 0, Route110_EventScript_PlayerNotRidingBike
	msgbox Route110_Text_AlwaysAimHigher, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_PlayerNotRidingBike::
	msgbox Route110_Text_RatedForNumberOfCollisions, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_PlayerRidingAcroBike::
	msgbox Route110_Text_AcroBikesDoNotQualify, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_Edward::
	trainerbattle_single TRAINER_EDWARD, Route110_Text_EdwardIntro, Route110_Text_EdwardDefeated
	msgbox Route110_Text_EdwardPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Jaclyn::
	trainerbattle_single TRAINER_JACLYN, Route110_Text_JaclynIntro, Route110_Text_JaclynDefeated
	msgbox Route110_Text_JaclynPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Edwin::
	trainerbattle_single TRAINER_EDWIN_1, Route110_Text_EdwinIntro, Route110_Text_EdwinDefeated, Route110_EventScript_EdwinRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route110_EventScript_EdwinRematch
	msgbox Route110_Text_EdwinPostBattle, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_EdwinRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route110_Text_EdwinRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_EDWIN_1
	release
	end

Route110_EventScript_EdwinRematch::
	trainerbattle_rematch TRAINER_EDWIN_1, Route110_Text_EdwinRematchIntro, Route110_Text_EdwinRematchDefeated
	msgbox Route110_Text_EdwinRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Dale::
	trainerbattle_single TRAINER_DALE, Route110_Text_DaleIntro, Route110_Text_DaleDefeated
	msgbox Route110_Text_DalePostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Jacob::
	trainerbattle_single TRAINER_JACOB, Route110_Text_JacobIntro, Route110_Text_JacobDefeated
	msgbox Route110_Text_JacobPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Anthony::
	trainerbattle_single TRAINER_ANTHONY, Route110_Text_AnthonyIntro, Route110_Text_AnthonyDefeated
	msgbox Route110_Text_AnthonyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Benjamin::
	trainerbattle_single TRAINER_BENJAMIN_1, Route110_Text_BenjaminIntro, Route110_Text_BenjaminDefeated, Route110_EventScript_BenjaminRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route110_EventScript_BenjaminRematch
	msgbox Route110_Text_BenjaminPostBattle, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_BenjaminRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route110_Text_BenjaminRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_BENJAMIN_1
	release
	end

Route110_EventScript_BenjaminRematch::
	trainerbattle_rematch TRAINER_BENJAMIN_1, Route110_Text_BenjaminRematchIntro, Route110_Text_BenjaminRematchDefeated
	msgbox Route110_Text_BenjaminRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Jasmine::
	trainerbattle_single TRAINER_JASMINE, Route110_Text_JasmineIntro, Route110_Text_JasmineDefeated
	msgbox Route110_Text_JasminePostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Abigail::
	trainerbattle_single TRAINER_ABIGAIL_1, Route110_Text_AbigailIntro, Route110_Text_AbigailDefeated, Route110_EventScript_AbigailRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route110_EventScript_AbigailRematch
	msgbox Route110_Text_AbigailPostBattle, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_AbigailRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route110_Text_AbigailRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ABIGAIL_1
	release
	end

Route110_EventScript_AbigailRematch::
	trainerbattle_rematch TRAINER_ABIGAIL_1, Route110_Text_AbigailRematchIntro, Route110_Text_AbigailRematchDefeated
	msgbox Route110_Text_AbigailRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Isabel::
	trainerbattle_single TRAINER_ISABEL_1, Route110_Text_IsabelIntro, Route110_Text_IsabelDefeated, Route110_EventScript_IsabelRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route110_EventScript_IsabelRematch
	msgbox Route110_Text_IsabelPostBattle, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_IsabelRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route110_Text_IsabelRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ISABEL_1
	release
	end

Route110_EventScript_IsabelRematch::
	trainerbattle_rematch TRAINER_ISABEL_1, Route110_Text_IsabelRematchIntro, Route110_Text_IsabelRematchDefeated
	msgbox Route110_Text_IsabelRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Timmy::
	trainerbattle_single TRAINER_TIMMY, Route110_Text_TimmyIntro, Route110_Text_TimmyDefeated
	msgbox Route110_Text_TimmyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Unused::
	end

Route110_EventScript_Kaleb::
	trainerbattle_single TRAINER_KALEB, Route110_Text_KalebIntro, Route110_Text_KalebDefeated
	msgbox Route110_Text_KalebPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Joseph::
	trainerbattle_single TRAINER_JOSEPH, Route110_Text_JosephIntro, Route110_Text_JosephDefeated
	msgbox Route110_Text_JosephPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Alyssa::
	trainerbattle_single TRAINER_ALYSSA, Route110_Text_AlyssaIntro, Route110_Text_AlyssaDefeated
	msgbox Route110_Text_AlyssaPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_CyclingChallengeEnd::
	lockall
	applymovement LOCALID_CHALLENGE_BIKER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	call Route110_EventScript_CyclingChallengeResults
	releaseall
	end

Route110_EventScript_CyclingChallengeResults::
	special FinishCyclingRoadChallenge
	msgbox Route110_Text_CyclingChallengeResultSummary, MSGBOX_DEFAULT
	switch VAR_RESULT
	case 10, Route110_EventScript_ChallengeReactionBest
	case 9, Route110_EventScript_ChallengeReactionGood
	case 8, Route110_EventScript_ChallengeReactionGood
	case 7, Route110_EventScript_ChallengeReactionGood
	case 6, Route110_EventScript_ChallengeReactionOk
	case 5, Route110_EventScript_ChallengeReactionOk
	case 4, Route110_EventScript_ChallengeReactionOk
	case 3, Route110_EventScript_ChallengeReactionBad
	case 2, Route110_EventScript_ChallengeReactionBad
	case 1, Route110_EventScript_ChallengeReactionBad
	case 0, Route110_EventScript_ChallengeReactionWorst
	end

Route110_EventScript_ChallengeReactionBest::
	msgbox Route110_Text_ChallengeReactionBest, MSGBOX_DEFAULT
	goto Route110_EventScript_EndChallenge
	end

Route110_EventScript_ChallengeReactionGood::
	msgbox Route110_Text_ChallengeReactionGood, MSGBOX_DEFAULT
	goto Route110_EventScript_EndChallenge
	end

Route110_EventScript_ChallengeReactionOk::
	msgbox Route110_Text_ChallengeReactionOk, MSGBOX_DEFAULT
	goto Route110_EventScript_EndChallenge
	end

Route110_EventScript_ChallengeReactionBad::
	msgbox Route110_Text_ChallengeReactionBad, MSGBOX_DEFAULT
	goto Route110_EventScript_EndChallenge
	end

Route110_EventScript_ChallengeReactionWorst::
	msgbox Route110_Text_ChallengeReactionWorst, MSGBOX_DEFAULT
	goto Route110_EventScript_EndChallenge
	end

Route110_EventScript_EndChallenge::
	setvar VAR_CYCLING_CHALLENGE_STATE, 3
	savebgm MUS_DUMMY
	fadedefaultbgm
	return

Route110_EventScript_RivalTrigger1::
	setvar VAR_0x8008, 1
	goto Route110_EventScript_RivalScene
	end

Route110_EventScript_RivalTrigger2::
	setvar VAR_0x8008, 2
	goto Route110_EventScript_RivalScene
	end

Route110_EventScript_RivalTrigger3::
	setvar VAR_0x8008, 3
	goto Route110_EventScript_RivalScene
	end

Route110_EventScript_RivalScene::
	lockall
    call Common_EventScript_SetupRivalMusic
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	delay 30
	call_if_eq VAR_0x8008, 1, Route110_EventScript_RivalApproachPlayer1
	call_if_eq VAR_0x8008, 2, Route110_EventScript_RivalApproachPlayer2
	call_if_eq VAR_0x8008, 3, Route110_EventScript_RivalApproachPlayer3
	getplayerstyle
	call_if_eq VAR_RESULT, STYLE_BRENDAN, Route110_EventScript_MayBattle
	call_if_eq VAR_RESULT, STYLE_MAY, Route110_EventScript_BrendanBattle
	call_if_eq VAR_RESULT, STYLE_RED, Route110_EventScript_MayBattle
	call_if_eq VAR_RESULT, STYLE_LEAF, Route110_EventScript_BrendanBattle
	call_if_eq VAR_RESULT, STYLE_ETHAN, Route110_EventScript_MayBattle
	call_if_eq VAR_RESULT, STYLE_LYRA, Route110_EventScript_BrendanBattle
	call_if_eq VAR_RESULT, STYLE_LUCAS, Route110_EventScript_MayBattle
	call_if_eq VAR_RESULT, STYLE_DAWN, Route110_EventScript_BrendanBattle
	call_if_eq VAR_RESULT, STYLE_HILBERT, Route110_EventScript_MayBattle
	call_if_eq VAR_RESULT, STYLE_HILDA, Route110_EventScript_BrendanBattle
	call_if_eq VAR_RESULT, STYLE_NATE, Route110_EventScript_MayBattle
	call_if_eq VAR_RESULT, STYLE_ROSA, Route110_EventScript_BrendanBattle
	call_if_eq VAR_RESULT, STYLE_CALEM, Route110_EventScript_MayBattle
	call_if_eq VAR_RESULT, STYLE_SERENA, Route110_EventScript_BrendanBattle
	call_if_eq VAR_RESULT, STYLE_ELIO, Route110_EventScript_MayBattle
	call_if_eq VAR_RESULT, STYLE_SELENE, Route110_EventScript_BrendanBattle
	call_if_eq VAR_RESULT, STYLE_VICTOR, Route110_EventScript_MayBattle
	call_if_eq VAR_RESULT, STYLE_GLORIA, Route110_EventScript_BrendanBattle
	call_if_eq VAR_RESULT, STYLE_FLORIAN, Route110_EventScript_MayBattle
	call_if_eq VAR_RESULT, STYLE_JULIANA, Route110_EventScript_BrendanBattle
	releaseall
	end

Route110_EventScript_MayBattle::
	msgbox Route110_Text_MayLetsBattle, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route110_EventScript_MayBattleTreecko
	case 1, Route110_EventScript_MayBattleTorchic
	case 2, Route110_EventScript_MayBattleMudkip
	end

Route110_EventScript_MayBattleTreecko::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_110_TREECKO, Route110_Text_MayDefeated
	goto Route110_EventScript_MayDefeated
	end

Route110_EventScript_MayBattleTorchic::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_110_TORCHIC, Route110_Text_MayDefeated
	goto Route110_EventScript_MayDefeated
	end

Route110_EventScript_MayBattleMudkip::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_110_MUDKIP, Route110_Text_MayDefeated
	goto Route110_EventScript_MayDefeated
	end

Route110_EventScript_MayDefeated::
	msgbox Route110_Text_MayTakeThis, MSGBOX_DEFAULT
	call Route110_EventScript_GiveItemfinder
	msgbox Route110_Text_MayExplainItemfinder, MSGBOX_DEFAULT
	goto Route110_EventScript_RivalExit
	end

Route110_EventScript_BrendanBattle::
	msgbox Route110_Text_BrendanLetsBattle, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route110_EventScript_BrendanBattleTreecko
	case 1, Route110_EventScript_BrendanBattleTorchic
	case 2, Route110_EventScript_BrendanBattleMudkip
	end

Route110_EventScript_BrendanBattleTreecko::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_TREECKO, Route110_Text_BrendanDefeated
	goto Route110_EventScript_BrendanDefeated
	end

Route110_EventScript_BrendanBattleTorchic::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_TORCHIC, Route110_Text_BrendanDefeated
	goto Route110_EventScript_BrendanDefeated
	end

Route110_EventScript_BrendanBattleMudkip::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_MUDKIP, Route110_Text_BrendanDefeated
	goto Route110_EventScript_BrendanDefeated
	end

Route110_EventScript_BrendanDefeated::
	msgbox Route110_Text_BrendanTakeThis, MSGBOX_DEFAULT
	call Route110_EventScript_GiveItemfinder
	msgbox Route110_Text_BrendanExplainItemfinder, MSGBOX_DEFAULT
	goto Route110_EventScript_RivalExit
	end

Route110_EventScript_GiveItemfinder::
	giveitem ITEM_DOWSING_MACHINE
	return

Route110_EventScript_RivalExit::
	closemessage
	call_if_eq VAR_0x8008, 1, Route110_EventScript_MoveRival1
	call_if_eq VAR_0x8008, 2, Route110_EventScript_MoveRival2
	call_if_eq VAR_0x8008, 3, Route110_EventScript_MoveRival3
	setobjectmovementtype LOCALID_RIVAL, MOVEMENT_TYPE_FACE_RIGHT
	setobjectmovementtype LOCALID_RIVAL_ON_BIKE, MOVEMENT_TYPE_FACE_RIGHT
	removeobject LOCALID_RIVAL
	addobject LOCALID_RIVAL_ON_BIKE
	delay 45
	call_if_eq VAR_0x8008, 1, Route110_EventScript_RivalExit1
	call_if_eq VAR_0x8008, 2, Route110_EventScript_RivalExit2
	call_if_eq VAR_0x8008, 3, Route110_EventScript_RivalExit3
	removeobject LOCALID_RIVAL_ON_BIKE
	setvar VAR_ROUTE110_STATE, 1
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

Route110_EventScript_RivalApproachPlayer1::
	applymovement LOCALID_RIVAL, Route110_Movement_RivalApproachPlayer1
	waitmovement 0
	return

Route110_EventScript_RivalApproachPlayer2::
	applymovement LOCALID_RIVAL, Route110_Movement_RivalApproachPlayer2
	waitmovement 0
	return

Route110_EventScript_RivalApproachPlayer3::
	applymovement LOCALID_RIVAL, Route110_Movement_RivalApproachPlayer3
	waitmovement 0
	return

Route110_EventScript_RivalExit1::
	applymovement LOCALID_RIVAL_ON_BIKE, Route110_Movement_RivalExit1
	waitmovement 0
	return

Route110_EventScript_RivalExit2::
	applymovement LOCALID_RIVAL_ON_BIKE, Route110_Movement_RivalExit2
	waitmovement 0
	return

Route110_EventScript_RivalExit3::
	applymovement LOCALID_RIVAL_ON_BIKE, Route110_Movement_RivalExit3
	waitmovement 0
	return

Route110_EventScript_MoveRival1::
	setobjectxyperm LOCALID_RIVAL_ON_BIKE, 33, 55
	return

Route110_EventScript_MoveRival2::
	setobjectxyperm LOCALID_RIVAL_ON_BIKE, 34, 55
	return

Route110_EventScript_MoveRival3::
	setobjectxyperm LOCALID_RIVAL_ON_BIKE, 35, 55
	return

Route110_Movement_RivalApproachPlayer1:
	walk_down
	walk_left
	walk_in_place_faster_down
	step_end

Route110_Movement_RivalApproachPlayer2:
	walk_down
	step_end

Route110_Movement_RivalApproachPlayer3:
	walk_down
	walk_right
	walk_in_place_faster_down
	step_end

Route110_Movement_RivalExit1:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Route110_Movement_RivalExit2:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_down
	step_end

Route110_Movement_RivalExit3:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Route110_EventScript_BirchScene1::
	lockall
	setvar VAR_0x8008, 1
	goto Route110_EventScript_BirchScene

Route110_EventScript_BirchScene2::
	lockall
	setvar VAR_0x8008, 2
	goto Route110_EventScript_BirchScene

Route110_EventScript_BirchScene3::
	lockall
	setvar VAR_0x8008, 3
	goto Route110_EventScript_BirchScene

Route110_EventScript_BirchScene4::
	lockall
	setvar VAR_0x8008, 4
	goto Route110_EventScript_BirchScene

Route110_EventScript_BirchScene::
	addobject LOCALID_BIRCH
	applymovement LOCALID_BIRCH, Route110_Movement_BirchEntrance
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_BIRCH, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_BIRCH, Common_Movement_Delay48
	waitmovement 0
	call_if_eq VAR_0x8008, 1, Route110_EventScript_BirchApproachPlayer1
	call_if_eq VAR_0x8008, 2, Route110_EventScript_BirchApproachPlayer2
	call_if_eq VAR_0x8008, 3, Route110_EventScript_BirchApproachPlayer3
	call_if_eq VAR_0x8008, 4, Route110_EventScript_BirchApproachPlayer4
	msgbox Route110_Text_ImagineSeeingYouHere, MSGBOX_DEFAULT
	closemessage
	delay 20
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 10
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 20
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 30
	msgbox Route110_Text_HeardYouInstallMatchCall, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox Route110_Text_RegisteredBirchInPokenav, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_PROF_BIRCH_MATCH_CALL
	msgbox Route110_Text_KeepAnEyeOutForRival, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, 1, Route110_EventScript_BirchExit1
	call_if_eq VAR_0x8008, 2, Route110_EventScript_BirchExit2
	call_if_eq VAR_0x8008, 3, Route110_EventScript_BirchExit3
	call_if_eq VAR_0x8008, 4, Route110_EventScript_BirchExit4
	removeobject LOCALID_BIRCH
	setvar VAR_REGISTER_BIRCH_STATE, 2
	releaseall
	end

Route110_EventScript_BirchApproachPlayer1::
	applymovement LOCALID_BIRCH, Route110_Movement_BirchApproachPlayer1
	waitmovement 0
	return

Route110_EventScript_BirchApproachPlayer2::
	applymovement LOCALID_BIRCH, Route110_Movement_BirchApproachPlayer2
	waitmovement 0
	return

Route110_EventScript_BirchApproachPlayer3::
	applymovement LOCALID_BIRCH, Route110_Movement_BirchApproachPlayer3
	waitmovement 0
	return

Route110_EventScript_BirchApproachPlayer4::
	applymovement LOCALID_BIRCH, Route110_Movement_BirchApproachPlayer4
	waitmovement 0
	return

Route110_EventScript_BirchExit1::
	applymovement LOCALID_BIRCH, Route110_Movement_BirchExit1
	waitmovement 0
	return

Route110_EventScript_BirchExit2::
	applymovement LOCALID_BIRCH, Route110_Movement_BirchExit2
	waitmovement 0
	return

Route110_EventScript_BirchExit3::
	applymovement LOCALID_BIRCH, Route110_Movement_BirchExit3
	waitmovement 0
	return

Route110_EventScript_BirchExit4::
	applymovement LOCALID_BIRCH, Route110_Movement_BirchExit4
	waitmovement 0
	return

Route110_Movement_BirchEntrance:
	walk_down
	walk_down
	walk_down
	step_end

Route110_Movement_BirchApproachPlayer1:
	walk_down
	walk_left
	walk_left
	walk_down
	step_end

Route110_Movement_BirchApproachPlayer2:
	walk_down
	walk_left
	walk_down
	step_end

Route110_Movement_BirchApproachPlayer3:
	walk_down
	walk_down
	step_end

Route110_Movement_BirchApproachPlayer4:
	walk_down
	walk_right
	walk_down
	step_end

Route110_Movement_BirchExit1:
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	step_end

Route110_Movement_BirchExit2:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route110_Movement_BirchExit3:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route110_Movement_BirchExit4:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route110_Text_WeCantTalkAboutAquaActivities:
	.string "TEAM AQUAs Aktivitäten müssen im\n"
	.string "Moment geheim bleiben!$"

Route110_Text_KickUpARuckus:
	.string "Ich würde liebend gerne nach\n"
	.string "GRAPHITPORT CITY gehen und ein\l"
	.string "bisschen Krawall machen.$"

Route110_Text_MyFirstJobInAqua:
	.string "Das ist mein erster Job, seit ich\n"
	.string "TEAM AQUA beigetreten bin. Ich bin\l"
	.string "ganz tatterig.$"

Route110_Text_AquaActionsBringSmiles:
	.string "TEAM AQUAs Aktionen zaubern ein\n"
	.string "Lächeln auf jedes Gesicht!$"

Route110_Text_MayLetsBattle:
	.string "MAIKE: Hi, {PLAYER}{KUN}, wir haben uns ja\n"
	.string "lange nicht gesehen!\p"
	.string "Während ich auf der Suche nach\n"
	.string "weiteren Pokémon war, sind meine\l"
	.string "Pokémon stärker geworden.\p"
	.string "Daher…\n"
	.string "Wie wäre es mit einem kleinen Kampf?$"

Route110_Text_MayDefeated:
	.string "AchDuSchande!\n"
	.string "Du bist besser, als ich gedacht habe.$"

Route110_Text_MayTakeThis:
	.string "MAIKE: {PLAYER}{KUN}, du hast auch fleißig\n"
	.string "trainiert, nicht wahr?\p"
	.string "Ich denke, du verdienst eine Belohnung!\n"
	.string "Hier, dies ist von mir für dich!$"

Route110_Text_MayExplainItemfinder:
	.string "MAIKE: Das ist ein DETEKTOR.\p"
	.string "Probier ihn mal aus. Wenn irgendwo ein\n"
	.string "Item versteckt ist, gibt er ein\l"
	.string "Geräusch von sich.\p"
	.string "Bis zum nächsten Mal, {PLAYER}{KUN}.\p"
	.string "Es hört sich aus meinem Munde zwar blöd\n"
	.string "an, aber bis dahin solltest du viel mehr\l"
	.string "trainiert haben.$"

Route110_Text_BrendanLetsBattle:
	.string "BRIX: Hey, {PLAYER}.\n"
	.string "Hier treibst du dich also herum.\l"
	.string "Wie geht es?\p"
	.string "Hast du deine Pokémon gut aufgezogen?\n"
	.string "Ich werde das für dich überprüfen.$"

Route110_Text_BrendanDefeated:
	.string "Hmm…\n"
	.string "Du bist sehr gut.$"

Route110_Text_BrendanTakeThis:
	.string "BRIX: {PLAYER}, du hast trainiert,\n"
	.string "ohne dass ich etwas davon\l"
	.string "mitbekommen habe…\p"
	.string "Aber genug!\n"
	.string "Hier, das ist für dich!$"

Route110_Text_BrendanExplainItemfinder:
	.string "BRIX: Das ist ein DETEKTOR.\p"
	.string "Probier ihn mal aus. \p"
	.string "Ist irgendwo ein Item versteckt, gibt\n"
	.string "er ein Geräusch von sich.\p"
	.string "Wie auch immer, ich suche jetzt weiter\n"
	.string "nach Pokémon.$"

Route110_Text_RideBikeAtFullSpeed:
	.string "Wäre das nicht ein Spaß, mit einem FAHR-\n"
	.string "RAD volle Pulle den RADWEG\l"
	.string "entlangzudüsen?$"

Route110_Text_HairStreamsBehindMe:
	.string "Gefällt es dir, wie mein raben-\n"
	.string "schwarzes Haar im Wind weht?\p"
	.string "Ich habe nur deshalb die Haare wachsen\n"
	.string "lassen!$"

Route110_Text_YouGotBikeFromRydel:
	.string "Oh, hey, du hast ein RAD von RADLA!\p"
	.string "Oh, das ist mehr als offensichtlich.\n"
	.string "Es steht ja dort geschrieben…\p"
	.string "RADLA, RADLA, RADLA, RADLA, RADLA,\n"
	.string "RADLA, RADLA, RADLA, RADLA, RADLA,\p"
	.string "RADLA, RADLA, RADLA, RADLA, RADLA,\n"
	.string "RADLA, RADLA, RADLA, RADLA, RADLA,\p"
	.string "RADLA, RADLA, RADLA, RADLA, RADLA,\n"
	.string "RADLA, RADLA, RADLA, RADLA, RADLA,\p"
	.string "RADLA, RADLA, RADLA, RADLA, RADLA,\n"
	.string "RADLA, RADLA, RADLA, RADLA, RADLA,\p"
	.string "RADLA, RADLA, RADLA, RADLA, RADLA…\n"
	.string "Der Name steht überall.\p"
	.string "Du solltest damit überall herumfahren,\n"
	.string "eine bessere Werbung gibt es nicht!$"

Route110_Text_TwoRoads:
	.string "Zwei Straßen, eine oben, eine unten…\p"
	.string "Eine Straße für Menschen und eine für\n"
	.string "Pokémon. Das ist nur recht und billig.$"

Route110_Text_WalkOnTheLowRoad:
	.string "Ich habe kein RAD, ich werde gemüt-\n"
	.string "lich über die untere Straße schlendern.$"

Route110_Text_BikeTechniques:
	.string "Neue Techniken zu lernen, gibt dem\n"
	.string "Radfahren erst die richtige Würze.\p"
	.string "Einige Orte kannst du nur erreichen,\n"
	.string "wenn du die richtige Technik anwendest.$"

Route110_Text_WhichShouldIChoose:
	.string "Was soll ich tun?\p"
	.string "Schnurstracks über den RADWEG nach\n"
	.string "MALVENFROH CITY fahren oder die untere\p"
	.string "Straße nehmen und nach Pokémon\n"
	.string "suchen?$"

Route110_Text_CyclingChallengeResultSummary:
	.string "Anzahl der Zusammenstöße:\n"
	.string "… … {STR_VAR_1}!\p"
	.string "Zeit:\n"
	.string "… … {STR_VAR_2}!$"

Route110_Text_ChallengeReactionBest:
	.string "Bravo! Eine hervorragende Leistung!\p"
	.string "Ich glaube, dein Talent zum Radfahren\n"
	.string "kommt tief aus deinem innersten Herzen.\l"
	.string "Du hast mich bis in die Seele getroffen!$"

Route110_Text_ChallengeReactionGood:
	.string "Deine Technik ist bemerkenswert.\p"
	.string "Achte stets darauf, dass du nicht zu\n"
	.string "schnell fährst und mit niemandem zu-\l"
	.string "sammenstößt.$"

Route110_Text_ChallengeReactionOk:
	.string "Ich rate dir, weiter zu üben.\p"
	.string "Und ich wünsche dir, dass du das Ver-\n"
	.string "gnügen des Radfahrens nie vergisst.$"

Route110_Text_ChallengeReactionBad:
	.string "Ich sage… dein Talent zum Radfahren\n"
	.string "ist einfach miserabel.\p"
	.string "Du brauchst wirklich noch viel mehr\n"
	.string "Übung im Radfahren.$"

Route110_Text_ChallengeReactionWorst:
	.string "… Ich bin entgeistert…\p"
	.string "Du hast wirklich kein Talent zum\n"
	.string "Radfahren.\p"
	.string "Du solltest ernsthaft darüber nach-\n"
	.string "denken, dein RAD bei RADLA\l"
	.string "zurückzugeben.$"

Route110_Text_RatedForNumberOfCollisions:
	.string "Dies ist der RADWEG.\p"
	.string "Wenn du mit einem EILRAD von MALVEN-\n"
	.string "FROH CITY nach GRAPHITPORT CITY\p"
	.string "fährst, wirst du nach der Anzahl der\n"
	.string "Zusammenstöße und deiner Zeit\l"
	.string "bewertet.$"

Route110_Text_AlwaysAimHigher:
	.string "Unabhängig von den Resultaten möchte\n"
	.string "ich mehr Herausforderungen von dir\l"
	.string "sehen. Immer das höchste Ziel im Auge\l"
	.string "behalten!$"

Route110_Text_AcroBikesDoNotQualify:
	.string "Auf diesem RADWEG werden die, die\n"
	.string "EILRÄDER fahren, nach ihren Zu-\l"
	.string "sammenstößen und ihrer Zeit bewertet.\p"
	.string "KUNSTRÄDER nehmen nicht am\n"
	.string "Wettkampf teil. Sie sind zu einfach\l"
	.string "zu lenken.$"

Route110_Text_SlateportCitySign:
	.string "ROUTE 110\n"
	.string "{DOWN_ARROW} GRAPHITPORT CITY$"

Route110_Text_CyclingRoadSign:
	.string "KÜSTENRADWEG$"

Route110_Text_AquaWasHere:
	.string "“TEAM AQUA war hier!”\p"
	.string "Das hat jemand auf das Schild\n"
	.string "gekritzelt. Ein anderer hat es \l"
	.string "überschrieben.\p"
	.string "“TEAM MAGMA ist das beste Team!”\n"
	.string "steht da nun.$"

Route110_Text_Route103Sign:
	.string "ROUTE 110\n"
	.string "{LEFT_ARROW} ROUTE 103$"

Route110_Text_SeasideParkingSign:
	.string "KÜSTENPARKPLATZ$"

Route110_Text_MauvilleCitySign:
	.string "ROUTE 110\n"
	.string "{UP_ARROW} MALVENFROH CITY$"

Route110_Text_TrainerTipsPrlzSleep:
	.string "TIPPS für TRAINER\p"
	.string "Der Gegner kann paralysiert oder\n"
	.string "in Schlaf versetzt werden und ist damit\l"
	.string "wehrlos.\p"
	.string "Das sind wichtige Techniken in einem\n"
	.string "Pokémon-Kampf.$"

Route110_Text_TrainerTipsRegisterItems:
	.string "TIPPS für TRAINER\p"
	.string "Die Items in dem BEUTEL können mit\n"
	.string "SELECT neu geordnet werden.$"

Route110_Text_TrickHouseSign:
	.string "“Drei Schritte {RIGHT_ARROW} und zwei Schritte {UP_ARROW}\n"
	.string "und du erreichst das wundersame\l"
	.string "RÄTSELHAUS.”$"

Route110_Text_BestRecord:
	.string "DAS BESTE ERGEBNIS…\p"
	.string "Anzahl der Zusammenstöße: {STR_VAR_1}\p"
	.string "Zeit: {STR_VAR_2}$"

Route110_Text_ThereIsNoRecord:
	.string "DAS BESTE ERGEBNIS…\p"
	.string "Niemand scheint sich bis jetzt der He-\n"
	.string "rausforderung gestellt zu haben…$"

Route110_Text_ImagineSeeingYouHere:
	.string "PROF. BIRK: Oh, {PLAYER}{KUN}!\n"
	.string "Ich dachte mir schon, dass ich dich hier\l"
	.string "treffe!\p"
	.string "Und wo mag {RIVAL} sein?$"

Route110_Text_HeardYouInstallMatchCall:
	.string "Ach so.\n"
	.string "Ihr beiden seid nicht zusammen\l"
	.string "unterwegs.\p"
	.string "Ich habe schon davon gehört. Dein\n"
	.string "POKéNAV ist mit dem TRAINER/RUF-\l"
	.string "System ausgerüstet.\p"
	.string "Dann werde ich dich in mein POKéNAV-\n"
	.string "Verzeichnis eintragen.\p"
	.string "So kann ich deinen POKéDEX beurteilen,\n"
	.string "auch wenn du weit weg bist.\p"
	.string "… … … … …\n"
	.string "…$"

Route110_Text_RegisteredBirchInPokenav:
	.string "PROF. BIRK wurde in das POKéNAV-\n"
	.string "Verzeichnis eingetragen.$"

Route110_Text_KeepAnEyeOutForRival:
	.string "PROF. BIRK: {PLAYER}{KUN}…\p"
	.string "Bitte achte ein wenig auf {RIVAL}.\n"
	.string "… … … … …\l"
	.string "…\p"
	.string "Nun muss ich mich aber beeilen.\n"
	.string "Man sieht sich, {PLAYER}{KUN}.$"

Route110_EventScript_Flemmli::
    msgbox Route110_Text_Flemmli, MSGBOX_NPC
    end

Route110_Text_Flemmli:
	.string "Tipp:\p"
	.string "Auf dieser Route versteckt sich ein\n"
	.string "Starter aus der 3 Generation mit\l"
	.string "einer Spawnrate von 1%!\p"
	.string "Welches es ist, musst du selbst\n"
	.string "herausfinden :D !$"
