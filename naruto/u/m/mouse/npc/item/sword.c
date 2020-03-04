#include <login.h>
#include <ansi.h>

inherit ITEM;

mapping record = ([
    1: ([ "name": HIR"������"NOR+BGRN"�츭��"NOR,
          "file": _DIR_AREA_"muye/inn.c", ]),

    2: ([ "name": "   "BBLU+HIW"�H���q"NOR"   ", 
          "file": _DIR_AREA_"whale_island/mite_hotel.c", ]),

    3: ([ "name": "�K�j�v�u�@��",
          "file": "/u/a/alickyuen/workarea.c",
          "x": 8,
          "y": 6, ]),

    4: ([ "name": "  "HIC"���Ť���"NOR"  ", 
          "file": _DIR_AREA_"old_forest/forest0.c", ]),
]);

void create()
{
    set_name(HIC"�Ƥ�"HIW"�l�P�C"NOR, ({ "Ao Tian Sword", "sword"}));
    set_weight(1);
    if( !clonep() ) {
        set("unit", "�`");
        set("value", -1);
        set("no_get", 1);
        set("long", "�@�`���a�ۼC�T���b�x�������C�A�C�����o�X���檺�H��A���H���H\n"
                    "�ӷX�C�������k��N�o��C�ޥX�O�H");
    }
    setup();
}
void init()
{
    add_action("do_fsword", "fsword");
    add_action("do_list", "list");
}
int do_fsword(string arg)
{
    int x, y, number;
    string file, out_msga, out_msgb, in_msg;
    object me = this_player(), room;

    out_msga = HIY"$N"HIY"���X�Q�A�f������q��A���M"NOR"$n"HIY"�u��v�a�@�n�q�C�T�����X�I\n"NOR;
    out_msgb = HIY"�u��$N"HIY"�@��½���D�W"NOR"$n"HIY"�A�f��C�Z�ֳt�a�����F���a�C\n\n"NOR;
    in_msg = "�|�g���M�ǥX�@�n�C�S�A�u��$N�s�۪��C���}�Ѫŭ����b�o�̡C\n"NOR;

    // �u���Ův�i�H�s�C
    if( !wizardp(me) ) {
        message_vision("$N�ӵۥ۾��W���G���F�@�M�A�o�S�o�ͥ���Ʊ��C\n", me);
        return 1;
    }

    // ���L�ξ԰������i�s�C
    if( me->is_busy() || me->is_fighting() ) 
        return notify_fail("�A�{�b�S���šC\n");

    // �S���w�ؼЪ�
    if( !arg )
        return notify_fail("�A�Q�n�ǰe����̡H\n");

    // ��ؼЪ����]�w���Ҧ����s���ж�
    if( sscanf(arg, "%d", number) == 1 ) {
        if( undefinedp(record[number]) )
            return notify_fail("�A�Q�n�ǰe����̡H\n");

        if( !objectp(room = load_object(record[number]["file"])) )
            return notify_fail("�A�{�b�L�k�ǰe�쨺�Ӧa��C\n");

        // ��s�����]�w�y�Юɫh�����y�Ц�m
        if( record[number]["x"] != 0 && record[number]["y"] != 0 ) {
            message_vision(out_msga, me, this_object());
            message_vision(out_msgb, me, this_object());
            area_move(room, me, record[number]["x"], record[number]["y"]);
            message_vision(in_msg, me);
            return 1;
        }
        message_vision(out_msga, me, this_object());
        message_vision(out_msgb, me, this_object());
        me->move(room);
        message_vision(in_msg, me);
        return 1;
    }

    // �����t�θ��Ҫ��ɮ�
    if( sscanf(arg, "%s %d %d", file, x, y) == 3 ) {
        file = resolve_path(me->query("cwd"), file);
        if( !sscanf(file, "%*s.c") ) file += ".c";
        if( file_size(file) >=0 && (room=load_object(file)) ) {
            if( !room->is_area() ) return 1;
            message_vision(out_msga, me, this_object());
            message_vision(out_msgb, me, this_object());
            area_move(room, me, x, y);
            message_vision(in_msg, me);
            return 1;
        } else {
            write("�o�Ӱϰ��ɤ��s�b�C\n");
            return 1;
        }
    }
    room = find_player(arg);
    if( !room ) room = find_living(arg);
    if( room == me ) {
        write("�A�n����ۤw���ǡH\n");
        return 1;
    }
    if( !room || !room->visible(me)) {
        arg = resolve_path(me->query("cwd"), arg);
        if( !sscanf(arg, "%*s.c") ) arg += ".c";
        if( file_size(arg) >=0 && (room=load_object(arg)) ) {
            if( room->is_area() ) {
                write("���ʨ�ϰ쪫��A���ݥ[�W�y�Ф~�ಾ�ʡC\n");
                return 1;
            }
            message_vision(out_msga, me, this_object());
            message_vision(out_msgb, me, this_object());
            me->move(room);
            message_vision(in_msg, me);
            return 1;
        } else return notify_fail("�o�Ӧa�褣�s�b�C\n");
    }

    // ���V�H��(id���i���_��)
    if( environment(room)->is_area() ) {
        if( area_environment(room, me) ) return notify_fail("�A�w�g�b�L���ǤF�C\n");
            message_vision(out_msga, me, this_object());
            message_vision(out_msgb, me, this_object());
        if( !area_move(environment(room), me, room->query("area_info/x_axis"), room->query("area_info/y_axis")) ) {
            tell_object(me, "�]���Y�زz�ѡA�A�� goto ���ѤF�C\n");
        }
    } else {
        message_vision(out_msga, me, this_object());
        message_vision(out_msgb, me, this_object());
        if( !me->move(environment(room)) ) {
            tell_object(me, "�]���Y�زz�ѡA�A�� goto ���ѤF�C\n");
        }
    }
    message_vision(in_msg, me);
    return 1;
}
int do_list()
{
    string msg;
    int index, size, x, y;

    // �u���Ův�~���D�ϥΤ�k
    if( !wizardp(this_player()) ) {
        msg  = "�~�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n";
        msg += "�x                                                �x\n";
        msg += "�x  "HIC"�t�s�W�H    �t��s��    �s�C�U��    �C�M����"NOR"  �x\n";
        msg += "�x                                                �x\n";
        msg += "�x  "HIY"�߸۫h�m    �߷Q�Ʀ�    ���C�}��    �S�ѦӦ�"NOR"  �x\n";
        msg += "�x                                                �x\n";
        msg += "���w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n\n";

        write(msg);
        return 1;
    }
    msg  = "�~�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n";
    msg += "�x                                                �x\n";
    msg += "�x  "HIC"�t�s�W�H    �t��s��    �s�C�U��    �C�M����"NOR"  �x\n";
    msg += "�x                                                �x\n";
    msg += "�x  "HIY"�߸۫h�m    �߷Q�Ʀ�    ���C�}��    �S�ѦӦ�"NOR"  �x\n";
    msg += "�x                                                �x\n";
    msg += "�u�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�t\n";
    msg += "�x�s��      �a��          (X,Y)�_�I��m           �x\n";
    msg += "�u�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n";

    if( (size=sizeof(record)) )
        for(index=1;index<=size;index++)
            if( record[index]["x"]==0 && record[index]["y"]==0 ) {
                msg += sprintf("�x%4d  %9s         �ж��L�y��\n", index, record[index]["name"]);
            } else {
                msg += sprintf("�x%4d  %9s         (%d,%d)\n", index, record[index]["name"], record[index]["x"], record[index]["y"]);
            }

    msg += "�u�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n";
    msg += "�xfsword <�H��>|<�ж�>|<�ϰ�> <X�y��> <Y�y��>     �x\n";
    msg += "���w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n\n";

    write(msg);
    return 1;
}
