const u8 gEasyChatWord_Meets[] = _("Trifft");
const u8 gEasyChatWord_Concede[] = _("Resignieren");
const u8 gEasyChatWord_Give[] = _("Geben");
const u8 gEasyChatWord_Gives[] = _("Gibt");
const u8 gEasyChatWord_Played[] = _("Spielte");
const u8 gEasyChatWord_Plays[] = _("Spielt");
const u8 gEasyChatWord_Collect[] = _("Sammeln");
const u8 gEasyChatWord_Walking[] = _("Wandern");
const u8 gEasyChatWord_Walks[] = _("Wandert");
const u8 gEasyChatWord_Says[] = _("Sagt");
const u8 gEasyChatWord_Went[] = _("Ging");
const u8 gEasyChatWord_Said[] = _("Sagte");
const u8 gEasyChatWord_WakeUp[] = _("Aufwachen");
const u8 gEasyChatWord_WakesUp[] = _("Wacht auf");
const u8 gEasyChatWord_Angers[] = _("Ärgert");
const u8 gEasyChatWord_Teach[] = _("Lehren");
const u8 gEasyChatWord_Teaches[] = _("Lehrt");
const u8 gEasyChatWord_Please[] = _("Bitte");
const u8 gEasyChatWord_Learn[] = _("Lerne");
const u8 gEasyChatWord_Change[] = _("Wechseln");
const u8 gEasyChatWord_Story[] = _("Story");
const u8 gEasyChatWord_Trust[] = _("Vertrauen");
const u8 gEasyChatWord_Lavish[] = _("Großzügig");
const u8 gEasyChatWord_Listens[] = _("Hört");
const u8 gEasyChatWord_Hearing[] = _("Gehört");
const u8 gEasyChatWord_Trains[] = _("Trainiert");
const u8 gEasyChatWord_Choose[] = _("Wählen");
const u8 gEasyChatWord_Come[] = _("Kommen");
const u8 gEasyChatWord_Came[] = _("Kam");
const u8 gEasyChatWord_Search[] = _("Suche");
const u8 gEasyChatWord_Make[] = _("Machen");
const u8 gEasyChatWord_Cause[] = _("Grund");
const u8 gEasyChatWord_Know[] = _("Wissen");
const u8 gEasyChatWord_Knows[] = _("Weiß");
const u8 gEasyChatWord_Refuse[] = _("Weigern");
const u8 gEasyChatWord_Stores[] = _("Lagert");
const u8 gEasyChatWord_Brag[] = _("Angeben");
const u8 gEasyChatWord_Ignorant[] = _("Ignorant");
const u8 gEasyChatWord_Thinks[] = _("Denkt");
const u8 gEasyChatWord_Believe[] = _("Glaube");
const u8 gEasyChatWord_Slide[] = _("Gleiten");
const u8 gEasyChatWord_Eats[] = _("Isst");
const u8 gEasyChatWord_Use[] = _("Gebrauchen");
const u8 gEasyChatWord_Uses[] = _("Gebraucht");
const u8 gEasyChatWord_Using[] = _("Verwenden");
const u8 gEasyChatWord_Couldnt[] = _("Können nicht");
const u8 gEasyChatWord_Capable[] = _("Fähig");
const u8 gEasyChatWord_Disappear[] = _("Verschwinde");
const u8 gEasyChatWord_Appear[] = _("Erscheinen");
const u8 gEasyChatWord_Throw[] = _("Werfen");
const u8 gEasyChatWord_Worry[] = _("Sorge");
const u8 gEasyChatWord_Slept[] = _("Schlief");
const u8 gEasyChatWord_Sleep[] = _("Schlaf");
const u8 gEasyChatWord_Release[] = _("Freilassen");
const u8 gEasyChatWord_Drinks[] = _("Trinkt");
const u8 gEasyChatWord_Runs[] = _("Rennt");
const u8 gEasyChatWord_Run[] = _("Rennen");
const u8 gEasyChatWord_Works[] = _("Sehen");
const u8 gEasyChatWord_Working[] = _("Arbeiten");
const u8 gEasyChatWord_Talking[] = _("Reden");
const u8 gEasyChatWord_Talk[] = _("Redet");
const u8 gEasyChatWord_Sink[] = _("Versenken");
const u8 gEasyChatWord_Smack[] = _("Schlag");
const u8 gEasyChatWord_Pretend[] = _("Vortäuschen");
const u8 gEasyChatWord_Praise[] = _("Loben");
const u8 gEasyChatWord_Overdo[] = _("Übertreiben");
const u8 gEasyChatWord_Show[] = _("Zeigen");
const u8 gEasyChatWord_Looks[] = _("Schaut");
const u8 gEasyChatWord_Sees[] = _("Sieht");
const u8 gEasyChatWord_Seek[] = _("Streben nach");
const u8 gEasyChatWord_Own[] = _("Besitzen");
const u8 gEasyChatWord_Take[] = _("Ertragen");
const u8 gEasyChatWord_Allow[] = _("Erlauben");
const u8 gEasyChatWord_Forget[] = _("Vergessen");
const u8 gEasyChatWord_Forgets[] = _("Vergisst");
const u8 gEasyChatWord_Appears[] = _("Erscheint");
const u8 gEasyChatWord_Faint[] = _("Besiegen");
const u8 gEasyChatWord_Fainted[] = _("Kampfunfähig");

const struct EasyChatWordInfo gEasyChatGroup_Actions[] = {
    [EC_INDEX(EC_WORD_MEETS)] =
    {
        .text = gEasyChatWord_Meets,
        .alphabeticalOrder = EC_INDEX(EC_WORD_ALLOW),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CONCEDE)] =
    {
        .text = gEasyChatWord_Concede,
        .alphabeticalOrder = EC_INDEX(EC_WORD_ANGERS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GIVE)] =
    {
        .text = gEasyChatWord_Give,
        .alphabeticalOrder = EC_INDEX(EC_WORD_APPEAR),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GIVES)] =
    {
        .text = gEasyChatWord_Gives,
        .alphabeticalOrder = EC_INDEX(EC_WORD_APPEARS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PLAYED)] =
    {
        .text = gEasyChatWord_Played,
        .alphabeticalOrder = EC_INDEX(EC_WORD_BELIEVE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PLAYS)] =
    {
        .text = gEasyChatWord_Plays,
        .alphabeticalOrder = EC_INDEX(EC_WORD_BRAG),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_COLLECT)] =
    {
        .text = gEasyChatWord_Collect,
        .alphabeticalOrder = EC_INDEX(EC_WORD_CAME),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WALKING)] =
    {
        .text = gEasyChatWord_Walking,
        .alphabeticalOrder = EC_INDEX(EC_WORD_CAPABLE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WALKS)] =
    {
        .text = gEasyChatWord_Walks,
        .alphabeticalOrder = EC_INDEX(EC_WORD_CAUSE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SAYS)] =
    {
        .text = gEasyChatWord_Says,
        .alphabeticalOrder = EC_INDEX(EC_WORD_CHANGE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WENT)] =
    {
        .text = gEasyChatWord_Went,
        .alphabeticalOrder = EC_INDEX(EC_WORD_CHOOSE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SAID)] =
    {
        .text = gEasyChatWord_Said,
        .alphabeticalOrder = EC_INDEX(EC_WORD_COLLECT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WAKE_UP)] =
    {
        .text = gEasyChatWord_WakeUp,
        .alphabeticalOrder = EC_INDEX(EC_WORD_COME),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WAKES_UP)] =
    {
        .text = gEasyChatWord_WakesUp,
        .alphabeticalOrder = EC_INDEX(EC_WORD_CONCEDE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ANGERS)] =
    {
        .text = gEasyChatWord_Angers,
        .alphabeticalOrder = EC_INDEX(EC_WORD_COULDN_T),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TEACH)] =
    {
        .text = gEasyChatWord_Teach,
        .alphabeticalOrder = EC_INDEX(EC_WORD_DISAPPEAR),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TEACHES)] =
    {
        .text = gEasyChatWord_Teaches,
        .alphabeticalOrder = EC_INDEX(EC_WORD_DRINKS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PLEASE)] =
    {
        .text = gEasyChatWord_Please,
        .alphabeticalOrder = EC_INDEX(EC_WORD_EATS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LEARN)] =
    {
        .text = gEasyChatWord_Learn,
        .alphabeticalOrder = EC_INDEX(EC_WORD_FAINT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CHANGE)] =
    {
        .text = gEasyChatWord_Change,
        .alphabeticalOrder = EC_INDEX(EC_WORD_FAINTED),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_STORY)] =
    {
        .text = gEasyChatWord_Story,
        .alphabeticalOrder = EC_INDEX(EC_WORD_FORGET),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TRUST)] =
    {
        .text = gEasyChatWord_Trust,
        .alphabeticalOrder = EC_INDEX(EC_WORD_FORGETS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LAVISH)] =
    {
        .text = gEasyChatWord_Lavish,
        .alphabeticalOrder = EC_INDEX(EC_WORD_GIVE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LISTENS)] =
    {
        .text = gEasyChatWord_Listens,
        .alphabeticalOrder = EC_INDEX(EC_WORD_GIVES),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HEARING)] =
    {
        .text = gEasyChatWord_Hearing,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HEARING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TRAINS)] =
    {
        .text = gEasyChatWord_Trains,
        .alphabeticalOrder = EC_INDEX(EC_WORD_IGNORANT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CHOOSE)] =
    {
        .text = gEasyChatWord_Choose,
        .alphabeticalOrder = EC_INDEX(EC_WORD_KNOW),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_COME)] =
    {
        .text = gEasyChatWord_Come,
        .alphabeticalOrder = EC_INDEX(EC_WORD_KNOWS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CAME)] =
    {
        .text = gEasyChatWord_Came,
        .alphabeticalOrder = EC_INDEX(EC_WORD_LAVISH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SEARCH)] =
    {
        .text = gEasyChatWord_Search,
        .alphabeticalOrder = EC_INDEX(EC_WORD_LEARN),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MAKE)] =
    {
        .text = gEasyChatWord_Make,
        .alphabeticalOrder = EC_INDEX(EC_WORD_LISTENS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CAUSE)] =
    {
        .text = gEasyChatWord_Cause,
        .alphabeticalOrder = EC_INDEX(EC_WORD_LOOKS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_KNOW)] =
    {
        .text = gEasyChatWord_Know,
        .alphabeticalOrder = EC_INDEX(EC_WORD_MAKE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_KNOWS)] =
    {
        .text = gEasyChatWord_Knows,
        .alphabeticalOrder = EC_INDEX(EC_WORD_MEETS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_REFUSE)] =
    {
        .text = gEasyChatWord_Refuse,
        .alphabeticalOrder = EC_INDEX(EC_WORD_OVERDO),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_STORES)] =
    {
        .text = gEasyChatWord_Stores,
        .alphabeticalOrder = EC_INDEX(EC_WORD_OWN),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BRAG)] =
    {
        .text = gEasyChatWord_Brag,
        .alphabeticalOrder = EC_INDEX(EC_WORD_PLAYED),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_IGNORANT)] =
    {
        .text = gEasyChatWord_Ignorant,
        .alphabeticalOrder = EC_INDEX(EC_WORD_PLAYS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THINKS)] =
    {
        .text = gEasyChatWord_Thinks,
        .alphabeticalOrder = EC_INDEX(EC_WORD_PLEASE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BELIEVE)] =
    {
        .text = gEasyChatWord_Believe,
        .alphabeticalOrder = EC_INDEX(EC_WORD_PRAISE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SLIDE)] =
    {
        .text = gEasyChatWord_Slide,
        .alphabeticalOrder = EC_INDEX(EC_WORD_PRETEND),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EATS)] =
    {
        .text = gEasyChatWord_Eats,
        .alphabeticalOrder = EC_INDEX(EC_WORD_REFUSE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_USE)] =
    {
        .text = gEasyChatWord_Use,
        .alphabeticalOrder = EC_INDEX(EC_WORD_RELEASE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_USES)] =
    {
        .text = gEasyChatWord_Uses,
        .alphabeticalOrder = EC_INDEX(EC_WORD_RUN),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_USING)] =
    {
        .text = gEasyChatWord_Using,
        .alphabeticalOrder = EC_INDEX(EC_WORD_RUNS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_COULDN_T)] =
    {
        .text = gEasyChatWord_Couldnt,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SAID),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CAPABLE)] =
    {
        .text = gEasyChatWord_Capable,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SAYS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DISAPPEAR)] =
    {
        .text = gEasyChatWord_Disappear,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SEARCH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_APPEAR)] =
    {
        .text = gEasyChatWord_Appear,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SEEK),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THROW)] =
    {
        .text = gEasyChatWord_Throw,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SEES),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WORRY)] =
    {
        .text = gEasyChatWord_Worry,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SHOW),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SLEPT)] =
    {
        .text = gEasyChatWord_Slept,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SINK),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SLEEP)] =
    {
        .text = gEasyChatWord_Sleep,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SLEEP),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RELEASE)] =
    {
        .text = gEasyChatWord_Release,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SLEPT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DRINKS)] =
    {
        .text = gEasyChatWord_Drinks,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SLIDE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RUNS)] =
    {
        .text = gEasyChatWord_Runs,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SMACK),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RUN)] =
    {
        .text = gEasyChatWord_Run,
        .alphabeticalOrder = EC_INDEX(EC_WORD_STORES),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WORKS)] =
    {
        .text = gEasyChatWord_Works,
        .alphabeticalOrder = EC_INDEX(EC_WORD_STORY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WORKING)] =
    {
        .text = gEasyChatWord_Working,
        .alphabeticalOrder = EC_INDEX(EC_WORD_TAKE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TALKING)] =
    {
        .text = gEasyChatWord_Talking,
        .alphabeticalOrder = EC_INDEX(EC_WORD_TALK),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TALK)] =
    {
        .text = gEasyChatWord_Talk,
        .alphabeticalOrder = EC_INDEX(EC_WORD_TALKING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SINK)] =
    {
        .text = gEasyChatWord_Sink,
        .alphabeticalOrder = EC_INDEX(EC_WORD_TEACH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SMACK)] =
    {
        .text = gEasyChatWord_Smack,
        .alphabeticalOrder = EC_INDEX(EC_WORD_TEACHES),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PRETEND)] =
    {
        .text = gEasyChatWord_Pretend,
        .alphabeticalOrder = EC_INDEX(EC_WORD_THINKS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PRAISE)] =
    {
        .text = gEasyChatWord_Praise,
        .alphabeticalOrder = EC_INDEX(EC_WORD_THROW),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OVERDO)] =
    {
        .text = gEasyChatWord_Overdo,
        .alphabeticalOrder = EC_INDEX(EC_WORD_TRAINS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SHOW)] =
    {
        .text = gEasyChatWord_Show,
        .alphabeticalOrder = EC_INDEX(EC_WORD_TRUST),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LOOKS)] =
    {
        .text = gEasyChatWord_Looks,
        .alphabeticalOrder = EC_INDEX(EC_WORD_USE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SEES)] =
    {
        .text = gEasyChatWord_Sees,
        .alphabeticalOrder = EC_INDEX(EC_WORD_USES),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SEEK)] =
    {
        .text = gEasyChatWord_Seek,
        .alphabeticalOrder = EC_INDEX(EC_WORD_USING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OWN)] =
    {
        .text = gEasyChatWord_Own,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WAKE_UP),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TAKE)] =
    {
        .text = gEasyChatWord_Take,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WAKES_UP),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ALLOW)] =
    {
        .text = gEasyChatWord_Allow,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WALKING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FORGET)] =
    {
        .text = gEasyChatWord_Forget,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WALKS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FORGETS)] =
    {
        .text = gEasyChatWord_Forgets,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WENT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_APPEARS)] =
    {
        .text = gEasyChatWord_Appears,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WORKING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FAINT)] =
    {
        .text = gEasyChatWord_Faint,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WORKS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FAINTED)] =
    {
        .text = gEasyChatWord_Fainted,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WORRY),
        .enabled = TRUE,
    },
};
