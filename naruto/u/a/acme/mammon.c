#include <npc.h>
#include <ansi.h>

inherit F_SAVE;

string *players;

// �s�ɪ����|�P����NPC���|�B�ɦW�@��
string query_save_file() { return file_name(this_object()); }

void create()
{
    set_name(HIR"�]����"NOR, ({ "mammon" }) );
    set_race("human");
    set_level(1);
    set("age", 99);
    set("gender", "male");
    set("long", "��������...(�A�i�H��]���ݻ���] receive gift )\n");

    setup();

    if( !restore() ) {
        players = ({});
        save();
    }
}

void init()
{
    add_action("do_receive", "receive");
}

int do_receive(string arg)
{
    if( !arg || arg != "gift" )
        return notify_fail("�A�n�������H\n");

    if( this_player()->query("level") < 20 )
        return notify_fail("�A�����Ť����G�Q�šA�L�k������]�I\n");

    if( member_array( this_player()->query_id(), players ) != -1 )
        return notify_fail("�A�w�g����L�F�C\n");

    message_vision(HIR"$N�µ�$n���U�A�Y�J�ýW�o�T�G�A�L���S�۶̯���...\n"NOR, this_player(), this_object() );
    tell_object(this_player(), "�]�A���f�U�̦h�F�@�Ӭ��]�C�^\n");

    players += ({ this_player()->query_id() });
    save();

    return 1;
}
