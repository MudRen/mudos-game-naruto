#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name(BCYN+HIC"�C��"NOR, ({ "sapphire" }));
    if( !clonep() ) {
        set("base_unit", "��");
        set("unit", "��");
        set("base_value", 20000);
        set("base_weight", 1);
        set("no_box", 1);
        set("long", "�C�Ŧ⪺�ɡA�ݤ[�F�|���H�Pı���P�߱��A�O���J�B��̳̳߷R����\n"
                    "�ۡA�䤤�����ū~�ť���p�j���A�|���H�i�\�ʪ��Pı�C");
    }
    setup();
}