#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name("�H��", ({ "paper" }));
    if( !clonep() ) {
        set("base_unit", "�i");
        set("unit", "�i");
        set("base_value", 2);
        set("base_weight", 10);
        set("long","�@�i�H�ȡA�i�H��(look �H��)�[�ݤ��e�C");
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
    if( arg == "�H��" ) {
        string line;
        line  = "�@\n";
        line += "�@�i�����W���ȡA�W���g�ۡG\n";
        line += "�@\n";
        line += "���˥ͫe�浹�ڪ��Ǯa�_���M����}���_�������n���b�A�֪�\n";
        line += "�ڨ��ѳܾK�s�ᳺ�M���p�ߧ�䤤���@�i���˱��F�I�֪��~�M\n";
        line += "�Q�@��k�ĵ��ߨ�I�o�٫¯٧ڦp�G�Q�n���^���i���b�N�n��\n";
        line += "�ڳo���������o�I�o�|���j�a���L�a�i�k���I���ǮɭԦo�n��\n";
        line += "�ڽͧP�A�ڤw�g��o���b�e�Y���K�Ǹ̤F�A�Ʊ�L�_�j�`�ެ�\n";
        line += "�b�u�@�M�ͱ������W�����ڳo�Ӧ��A�b�ͧP�e�N�N�����b����\n";
        line += "�^�ӡI�ڦb�s���������`�ު��n�����I\n";
        line += "�@\n";
        line += "�@\n";
        write(line);
        return 1;
    }
}
