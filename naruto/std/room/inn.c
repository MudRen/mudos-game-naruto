// inn.c
// update by -Acme-

inherit ROOM;

void setup()
{
    ::setup();
    set("valid_startroom", 1);
    set("no_fight", 1);
    set("recoverroom", 1);   // 角色在此room save後，角色死亡會由此重生
}