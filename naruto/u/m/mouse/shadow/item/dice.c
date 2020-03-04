inherit ITEM;
#include <ansi.h>

string *unk_msg = ({
        YEL"�j�N"NOR, HIY"�N"NOR, HIY"�p�N"NOR, HIW"��"NOR, 
        HIK"�p��"NOR, HIR"��"NOR, RED"�j��"NOR,
});

void create()
{
        set_name(HIW"�R�B��l"NOR, ({ "dice"}));
        set_weight(1);
        if( !clonep() ) {
                set("unit", "��");
                set("value", 5);
                set("long","�@�ɻ�l�A�i�H�� roll �Y��l���C\n");
        }
        setup();
}
void init()
{
        add_action("do_roll", ({ "roll", "throw" }));
}
int do_roll(string arg)
{
        string msg;
        if( !id(arg) ) return 0;
        msg = unk_msg[random(sizeof(unk_msg))];
        message_vision("$N���X��l�@�Y�A��l�u�F�u���U�ӡA���G�O"+msg+"�I\n", this_player());
        return 1;
}
