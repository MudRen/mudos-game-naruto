#include <ansi.h>
#include <room.h>
#define N 12
#define PAY 50000
#define MOVE "/world/area/wizard/guildhall.c"

inherit INN;

string symbol = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890=[]\\;/!@#$%^&*(){}|:<>?";

mixed *NUM;

void create()
{
    int i, j;

    set("short", HIR"���c"NOR);
    set("long", "�A�]�H�ϵ��}���U�ӳQ���|�A�Y�A�Q���}(leave)�����I�@�ǹL���O�C\n"
                "�Y�A�s�L���O���I���X�ӡA���N���u�W�Ův�����A�����a�I\n" );
    setup();

    // �n�D�O����
    NUM = allocate(10);
    for(i=0;i<10;i++) {
        NUM[i] = allocate(5);
        for(j=0;j<5;j++)
            NUM[i][j] = allocate(5);
    }

    NUM[0][0] = ({ 1,1,1,1,1, });
    NUM[0][1] = ({ 1,0,0,0,1, });
    NUM[0][2] = ({ 1,0,0,0,1, });
    NUM[0][3] = ({ 1,0,0,0,1, });
    NUM[0][4] = ({ 1,1,1,1,1, });

    NUM[1][0] = ({ 1,1,1,0,0, });
    NUM[1][1] = ({ 0,0,1,0,0, });
    NUM[1][2] = ({ 0,0,1,0,0, });
    NUM[1][3] = ({ 0,0,1,0,0, });
    NUM[1][4] = ({ 1,1,1,1,1, });

    NUM[2][0] = ({ 1,1,1,1,1, });
    NUM[2][1] = ({ 0,0,0,0,1, });
    NUM[2][2] = ({ 1,1,1,1,1, });
    NUM[2][3] = ({ 1,0,0,0,0, });
    NUM[2][4] = ({ 1,1,1,1,1, });


    NUM[3][0] = ({ 1,1,1,1,1, });
    NUM[3][1] = ({ 0,0,0,0,1, });
    NUM[3][2] = ({ 1,1,1,1,1, });
    NUM[3][3] = ({ 0,0,0,0,1, });
    NUM[3][4] = ({ 1,1,1,1,1, });

    NUM[4][0] = ({ 1,0,0,0,1, });
    NUM[4][1] = ({ 1,0,0,0,1, });
    NUM[4][2] = ({ 1,1,1,1,1, });
    NUM[4][3] = ({ 0,0,0,0,1, });
    NUM[4][4] = ({ 0,0,0,0,1, });

    NUM[5][0] = ({ 1,1,1,1,1, });
    NUM[5][1] = ({ 1,0,0,0,0, });
    NUM[5][2] = ({ 1,1,1,1,1, });
    NUM[5][3] = ({ 0,0,0,0,1, });
    NUM[5][4] = ({ 1,1,1,1,1, });

    NUM[6][0] = ({ 1,1,1,1,1, });
    NUM[6][1] = ({ 1,0,0,0,0, });
    NUM[6][2] = ({ 1,1,1,1,1, });
    NUM[6][3] = ({ 1,0,0,0,1, });
    NUM[6][4] = ({ 1,1,1,1,1, });

    NUM[7][0] = ({ 1,1,1,1,1, });
    NUM[7][1] = ({ 1,0,0,0,1, });
    NUM[7][2] = ({ 0,0,0,0,1, });
    NUM[7][3] = ({ 0,0,0,0,1, });
    NUM[7][4] = ({ 0,0,0,0,1, });

    NUM[8][0] = ({ 1,1,1,1,1, });
    NUM[8][1] = ({ 1,0,0,0,1, });
    NUM[8][2] = ({ 1,1,1,1,1, });
    NUM[8][3] = ({ 1,0,0,0,1, });
    NUM[8][4] = ({ 1,1,1,1,1, });

    NUM[9][0] = ({ 1,1,1,1,1, });
    NUM[9][1] = ({ 1,0,0,0,1, });
    NUM[9][2] = ({ 1,1,1,1,1, });
    NUM[9][3] = ({ 0,0,0,0,1, });
    NUM[9][4] = ({ 1,1,1,1,1, });
}

void init()
{
    this_player()->set("startroom","/world/area/jail.c");
    this_player()->set("recoverroom","/world/area/jail.c");
    add_action("do_recall", "recall");
    add_action("do_leave", "leave");
}

int do_recall(string arg)
{
    tell_object(this_player(), "�b�o�̤���ϥγo��\�\��C\n");
    return 1;
}

void create_ask(object who)
{
    int i;
    string ask = "";
    for(i=0;i<N;i++) ask += ""+random(10);
    who->set_temp("jail", ask);
}

void show_ask(object who)
{
    int i, j, k, rnd;
    string numbers, msg = "";

    if( !objectp(who) ) return;
    numbers = who->query_temp("jail");

    for(i=0;i<5;i++) {
        for(j=0;j<N;j++) {
            for(k=0;k<5;k++ ) {
                if( NUM[atoi(numbers[j..j])][i][k] ) {
                    rnd = random(sizeof(symbol));
                    msg += symbol[rnd..rnd];
                } else msg += " ";
            }
            msg += "  ";
        }
        msg += "\n";
    }
    msg += "\n";
    tell_object(who, msg);
}

void do_ask(string arg, object who)
{
    if( arg != who->query_temp("jail") ) {
        tell_object(who, "�A�����פ����T...\n");
        return;
    }

    who->add("bank", -PAY);
    who->move(MOVE);
}

int do_leave(string arg)
{
    if( this_player()->query("bank") < PAY ) {
        tell_object(this_player(), "�A���Ȧ�̤����H�I�L���O�C\n");
        return 1;
    }

    create_ask(this_player());
    show_ask(this_player());
    tell_object(this_player(), "�Y�A�Q�X�h�A�Х��^���W�����Ʀr�H");
    input_to("do_ask", this_player());

    return 1;
}
