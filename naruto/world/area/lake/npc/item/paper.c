#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name("������", ({ "paper" }));
    if( !clonep() ) {
        set("base_unit", "�i");
        set("unit", "�i");
        set("base_value", 2);
        set("base_weight", 200);
        set("long","�@�i�����������ȡA�i�H��(look ������)���[�ݡC");
    }
    setup();
}
void init()
{
    add_action("do_look", "look");
}
int do_look(string arg)
{
    if( !arg ) return 0;
    if( arg == "������" ) {
        string line;
        line  = "�@\n";
        line += "�q�L�_�����ͨ��W���쪺�����}�k�A�i�H�צh���N�����D�F\n";
        line += "�@\n";
        line += "    ���w��  158        �s��(�})   ���s�}158���}�s���A�`�N�P�e�ǽĬ�\n";
        line += "    �x  �x  851        �s��(��)   ��������~��}�ҵe��\n";
        line += "    ���w��  623        �e��(�})   ���s�}623���}�e�ǡA�`�N�P�s���Ĭ�\n";
        line += "    �x  �x  326        �e��(��)   ��������~��}�Ұs��\n";
        line += "    ���w��  6461587    �_�ö�(�}) ���}�Ұs��6�Ұʤ��þ���4�A�}�ҵe��158���}�_�ö�7\n";
        line += "    �x  �x  857162426  �_�ö�(��) �������e��85�����_�ö�7�A�}�Ұs��62�������þ���4\n";
        line += "    ���w��             ���G�s���_�ö��é���y�����A�e�ǫh�b�p�B�͵e�Ǥ��U\n";
        line += "�@\n";
        line += "�@\n";
        write(line);
        return 1;
    }
}
