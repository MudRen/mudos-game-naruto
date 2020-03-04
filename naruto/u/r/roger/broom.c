#include <ansi.h>

inherit ITEM;

#define MAX 2   /* ��O�Ъ��ƶq */

string *path = allocate(MAX);
string *name = allocate(MAX);
int *x = allocate(MAX);
int *y = allocate(MAX);

void create()
{
        set_name("���ѱ���", ({ "flying broom", "broom"}));
        set_weight(3);
        if( !clonep() ) {
                set("unit", "��");
                set("value", 10000);
                set("long",@LONG
�o�O�@�ڥѤj���H�]�k�ХX�Ӫ����ѱ����A�A�i�H�ϥΥ��ֳt�a���ʨ��
��A�Q�h���a��A��M�A�e���O�A�����n���O��(remember)�n�h���ت��a�C��
�󭸤ѱ����Q�s�y�ɪ��]�k�ĪG���@�A�ҥH�֦����P�{�ת��O�Я�O�A���ǥu
��O���G�Ӧa�I�A���ǫo��O�����Ӧa�I�H�W�A�O�Я�O�V���������A��M�V
�O���ȳs���C

���O�榡�G
remember [id] : �N�A�ثe���Ҧb�a�O���b��id�ӽs��
remember      : �C�X�C�@��id�ҰO�����ت��a
move [id]     : ���ʨ�A���e��id�ӽs���ҰO���Ҧb�a

LONG
);
        }
        setup();
}

void init()
{
        add_action("do_move", "move");
        add_action("do_remember", "remember");
}

//void moveTo(string files, int x, int y);
void moveTo(int index);

int do_remember(string arg)
{
        if( !arg ) {
                int i;
//                string msg = "ID: �a�I\n";
        string msg  = "�~�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n";
                msg += sprintf("�x"BRED"%|4s"NOR" "BBLU"%|50s"NOR" �x\n", "�s��", "�a�I");
                for(i=1;i<=MAX;i++) {
                        if( !stringp(path[i-1])) {
//                                msg += sprintf("%2d: [�L]\n", i );
                msg += sprintf("�x%|4d %-50s �x\n", i, "[�L]");
                        } else {
//                                msg += sprintf("%2d: %s at (%3d,%3d)\n", i, name[i-1], x[i-1], y[i-1] );
                msg += sprintf("�x%|4d %-50s �x\n", i, name[i-1] + " (" + x[i-1] + "," + y[i-1] + ")");
                        }
                }
        msg += "���w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n";
                tell_object(this_player(), msg );
        } else {
                string file;
                int id;
                object me = this_player();
                if(sscanf(arg, "%d", id) != 1 || id < 1 || id > MAX ) return notify_fail("�����T��id�s���C\n");  
                if( !environment(me)->is_area() ) return notify_fail("�A�L�k�O���ثe�ҳB���a�I�C\n");
                file = base_name(environment(me)) + ".c";
                path[id-1] = file;
                name[id-1] = environment(me)->query("name");
                x[id-1] = me->query("area_info/x_axis");
                y[id-1] = me->query("area_info/y_axis");
                write("�A�J�ӱN�|�g������O�F�U�ӡC\n");
        }
        return 1;
}

int do_move(string arg)
{
        int id;
        if( !arg ) return notify_fail("�A�Q�n���ʨ줰��a��H\n");
        if( sscanf(arg, "%d", id) != 1 || id < 1 || id > MAX ) return notify_fail("�����T��id�s���C\n");        
        if( !stringp(path[id-1]))  return notify_fail("�o��id�s���èS���O�������a�I�C\n");
        if( this_player()->is_busy() || this_player()->is_fighting() ) return notify_fail("�A�����ۡA�S���Ų��ʡC\n");
        moveTo( id-1 );
    return 1;
}

//void moveTo(string file, int x, int y) {
void moveTo(int index) {
        string file;
        int xc,yc;
    // goto ��ϰ� by -Acme-
        object obj;
        object me = this_player();

                file = path[index];
                xc = x[index];
                yc = y[index];
        if( file_size(file) >=0 && (obj=load_object(file)) ) {
        if( !obj->is_area() ) return;
               message_vision(HIW"$N�M�W�F���ѱ����A���a�@�n["+name[index]+"]���h...\n"NOR, me);
                       area_move(obj, me, xc, yc);
               message_vision(HIW"$N�M�ۭ��ѱ������]���a��F�o��...\n" NOR, me);
                return;
        }
 
       write("�]���Y�ǩ_�Ǫ���]�A�A�L�k���ʨ쨺�Ӱϰ�C\n");
}

