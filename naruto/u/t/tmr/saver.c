#include <armor.h>

inherit F_NECK_EQ;

void create()
{
        set_name("�����a�s��", ({ "players saver","saver"}));
        set_weight(3);
            setup_neck_eq();
        if( !clonep() ) {
                set("wear_as", "neck_eq");
                set("unit", "��");
                set("value", 5);
                set("long",
                        "�ϥΫ��O�Gsaveall\n");
        }
        setup();
}

void init()
{
        if( wizardp(this_player() ) )
         add_action("do_saveall", "saveall");
}

int do_saveall(string arg)
{
        users()->save();
    write("ok\n");
        return 1;
}
