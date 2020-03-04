/* write by -Acme- */
#include <ansi.h>
#define GUILD "mu"
#define GUILD_NAME "muye"
 
inherit ROOM;
 
// ���Ѫ�����
int *quests = ({ 2, 3, 4, 5 });
 
string do_list()
{
    int index, size;
    string msg;
    mapping q;
 
    msg  = "\n�~�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n";
    msg += sprintf("�x%-58s�x\n", this_object()->query("short"));
    msg += "�u�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�t\n";
    msg += sprintf("�x"BRED"%6s"NOR" "BBLU"%|51s"NOR"�x\n", " �s�� ", " ���ȦW�� ");
 
    size = sizeof(quests);
    for(index=0;index<size;index++) {
        if( mapp(q = QUEST_D->query_quest(GUILD, quests[index])) ) {
            msg += sprintf("�x%|6d%s%-51s�x\n",
                    index+1,
                    this_player()->query_quest(GUILD, quests[index]) ? HIY"a"NOR : " ",
                    q["name"] );
        }
    }

    msg += "���w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��";
    return msg;
}

void create()
{
    set("short", "�츭�����ȱ�����");

    set("long", "�A�i�H�b�o�̱��U�츭���Ҵ��Ѫ����ȡC\n"
                "��J list   �d�ߥ��ȦC��\n"
                "��J accept ��������\n"
                "��J giveup ������\n");

    set("exits", ([
        "east" : ([ "filename": __DIR__"muye.c",
                      "x_axis": 11,
                      "y_axis": 10,
                 ]),
    ]));

    setup();
}

void init()
{
    add_action("do_accept", "accept");
    add_action("do_giveup", "giveup");
}

int do_accept(string arg)
{
    int no;
    
    if( !arg ) return notify_fail("�A�n���U���@�ӥ��ȡH\n");
    if( sscanf(arg, "%d", no) != 1 ) return notify_fail("�A�n���U���@�ӥ��ȡH\n");
/*  �ɯť��ȯ�q�� -Tmr 2005/10/22
    if( this_player()->query("guild") != GUILD_NAME )
        return notify_fail("�A���O�츭���������A���౵�����ȡC\n");
*/

    no -= 1;
    if( no < 0 || no >= sizeof(quests) ) return notify_fail("�A�n���U���@�ӥ��ȡH\n");

    if( this_player()->query_quest(GUILD, quests[no]) )
        return notify_fail("�A�w�g���U�o�ӥ��ȤF�C\n");

    this_player()->add_quest(GUILD, quests[no], 1);
    
    tell_object(this_player(), "�A���U�F�o�ӥ��ȡI\n");

        return 1;
}

int do_giveup(string arg)
{
    int no;

    if( !arg ) return notify_fail("�A�n�����@�ӥ��ȡH\n");
    if( sscanf(arg, "%d", no) != 1 ) return notify_fail("�A�n�����@�ӥ��ȡH\n");
/*
    if( this_player()->query("guild") != GUILD_NAME )
        return notify_fail("�A���O�츭���������A��������ȡC\n");
*/

    no -= 1;


    if( no < 0 || no >= sizeof(quests) ) return notify_fail("�A�n�����@�ӥ��ȡH\n");

    if( !this_player()->query_quest(GUILD, quests[no]) )
        return notify_fail("�A�èS�����U�o�ӥ��ȡC\n");
    
    this_player()->delete_quest(GUILD, quests[no]);
    
    tell_object(this_player(), "�A�w�g���F�o�ӥ��ȡC\n");

        return 1;
}

