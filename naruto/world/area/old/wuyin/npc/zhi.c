#include <npc.h>

inherit F_VILLAGER;

void create()
{
        set_name("�|��", ({ "lu zhi", "zhi" }) );
        set_race("human");
        set_level(20);
        set("title","�K�v");
        set("age", 70);
        set("long", "�u�K���j�v�A�Ǩ����y�u�|�Ī��e�ˤj��v��ܥX�|�Ī��޳N���W�A\n"
                 "���O�@��H�i�H�������A�ڶǾ|�ĬO�|�Z������S��...\n" );

        setup();
}
