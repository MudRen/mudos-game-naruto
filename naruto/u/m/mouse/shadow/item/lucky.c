inherit ITEM;
#include <ansi.h>

string *unk_msg = ({
        YEL"�j�N"NOR, HIY"�N"NOR, HIY"�p�N"NOR, HIW"��"NOR, 
        HIK"�p��"NOR, HIR"��"NOR, RED"�j��"NOR,
});

void create()
{
    set_name(HIY"���B��"NOR, ({ "lucky"}));
    set_weight(1);
    if( !clonep() ) {
        set("unit", "�O");
        set("value", 0);
        set("no_get", 1);
        set("long","�@�O���j�����B���A�i�H���(pull)�ݬݷ|���X����C\n");
    }
    setup();
}
void init()
{
    add_action("do_pull", "pull" );
}
int do_pull(string arg)
{
    string msg;
    int i;
    msg = unk_msg[random(sizeof(unk_msg))];
    if( !id(arg) ) return notify_fail("�A�Q��ʤ���H\n");
    message_vision("$N��F("HIY"100"NOR")���A�ΤO�����$n�C\n", this_player(), this_object());
    this_player()->add("bank", -100);
    message_vision("$n"HIW"�����X�@���ȡA$N���}���X���ȱi�A�W���g�ۡu"NOR+msg+HIW"�v\n"NOR, this_player(), this_object());
    return 1;
}
