#include <ansi.h>

inherit ITEM;

#define MAX 3   /* ��O�Ъ��ƶq */

string *path = allocate(MAX);
string *name = allocate(MAX);
string *eid = allocate(MAX);

void create()
{
    set_name(HIW"�ն����ѷƪO"NOR, ({ "cloud flying skateboard", "skateboard"}));
    set_weight(3);
    if( !clonep() ) {
        set("unit", "��");
        set("value", 40000);
        set("long",@LONG
�o�O�@�ӥѮ��x�u�Хά�޳ХX�Ӫ����ѷƪ��A�A�i�H�ϥΥ��ֳt�a���ʨ��
�w�����a���ǡA��M�A�e���O�A�����n���O��(assign)���쪱�a���עҡC�ѩ�
���ѷƪO�s�y�ɷ|���ͨ}�~�P���}�~�A�ҥH�֦����P�{�ת��O�Я�O�A���ǥu
��O���G�ӢעҡA���ǫo��O�����ӢעҥH�W�A�O�Я�O�V�����ƪO�A��M�V
�O���ȳs���C

���O�榡�G
assign [�s��] [ID] : �N�s���O�ЬY���a���^��ע�
assign             : �C�X�C�@�ӽs���ҰO�������e
sfly [�s��]        : ���ʨ�A�ҰO���L�����a����

LONG
);
    }
    setup();
}

void init()
{
    add_action("do_move", "sfly");
    add_action("do_remember", "assign");
}

void moveTo(int index);

int do_remember(string arg)
{
    if( !arg ) {
        int i;
        string msg  = "�~�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n";
        msg += sprintf("�x"BRED"%|4s"NOR" "BBLU"%|50s"NOR" �x\n", "�s��", "�H��");
        for(i=1;i<=MAX;i++) {
            if( !stringp(path[i-1])) {
                msg += sprintf("�x%|4d %-50s �x\n", i, "[�L]");
            } else {
                msg += sprintf("�x%|4d %-50s �x\n", i, name[i-1] + "(" + eid[i-1] + ")");
            }
        }
        msg += "���w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n";
        tell_object(this_player(), msg );
    } else {
        string ppl;
        object me, ob;
        int id;

        me = this_player();

        if(sscanf(arg, "%d %s", id, ppl) != 2 || id < 1 || id > MAX ) return notify_fail("�ϥΤ�k�� assign [�s��] [ID]�C\n");

        if( !(ob = present(ppl, environment(me))) )
            return notify_fail(HIB"�o�̨S�� "NOR+ppl+HIB" �o�ӤH���C\n"NOR);

        if( !userp(ob) || wizardp(ob) )
            return notify_fail(HIB"�A�u�i�H�O�Ъ��a���עҡC\n"NOR);

        if( ppl == this_player()->query("id") )
            return notify_fail(HIB"�O�ЧA�ۤv���עҰ�ԣ�C\n"NOR);

        path[id-1] = ob->query("name");
        name[id-1] = ob->query("name");
        eid[id-1] = ob->query("id");
        write("�A���_�ƪO�W���O�о���"+ob->query("name")+"�r�ӡC\n");
    }
    return 1;
}

int do_move(string arg)
{
    int id;
    if( !arg ) return notify_fail("�A�Q�n���ʨ���ӽs���H\n");
    if( sscanf(arg, "%d", id) != 1 || id < 1 || id > MAX ) return notify_fail("�����T���s���C\n");        
    if( !stringp(path[id-1]))  return notify_fail("�o�ӽs���èS���O�������עҡC\n");
    if( this_player()->is_busy() || this_player()->is_fighting() ) return notify_fail("�A�����ۡA�S���Ų��ʡC\n");
    moveTo( id-1 );
    return 1;
}

void moveTo(int index)
{
    object ob = LOGIN_D->find_body(eid[index]);
    object me = this_player();
    string obj = this_object()->query("name");

    if( !ob ) {
        tell_object(me,HIB"�A���w��"+name[index]+"�ثe���b�u�W�C\n"NOR);
        return;
    }
    if( environment(ob)->query("no_recall") == 1 ) {
        tell_object(me,HIB""+name[index]+"�Ҧb����m���G����L�h�C\n"NOR);
        return;
    }
    if( environment(ob)->is_area() ) {
        if( area_environment(ob, me) ) {
            tell_object(me, "�A�w�g�b"+name[index]+"���ǤF�C\n");
            return;
        }
        message_vision(HIC"$N��}��b"+obj+"�W�A���a�@�n�ֳt���V�ѻ�...\n"NOR, me);
        if( !area_move(environment(ob), me, ob->query("area_info/x_axis"), ob->query("area_info/y_axis")) ) {
            tell_object(me, obj+"�X���D�աI���I�e�����קa�C\n");
            return;
        }
        message_vision(HIC"$N���Q�������b["+name[index]+"]���ǡC\n" NOR, me);
        return;
    } else {
        if( environment(ob) == environment(me) ) {
            tell_object(me, "�A�w�g�b"+name[index]+"���ǤF�C\n");
            return;
        }
        message_vision(HIC"$N��}��b"+obj+"�W�A���a�@�n�ֳt���V�ѻ�...\n"NOR, me);
        if( !me->move(environment(ob)) ) {
            tell_object(me, obj+"�X���D�աI���I�e�����קa�C\n");
            return;
        }
        message_vision(HIC"$N���Q�������b["+name[index]+"]���ǡC\n" NOR, me);
        return;
    }
}
