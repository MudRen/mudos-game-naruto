/* poker table

    ��J�P - �j�ѤG
    
    �ܼơG
    clear(���]�P��)    0-���]�P��, 1-�P�����]
    start(�}�l�C��)    0-���}�l, 1-�}�l
    focus(�X�P�v)    0-����, 1-palyer1�X�P, 2-player2�X�P, 3-player3�X�P�A4-player4�X�P
    play_kind(�X�P�覡) 0-�H�N, 1-�m��, 2-��l, 3-��Ī, 4-���l, 5-�K��, 6-�P�ᶶ, 7-������T
    owner        �P���W�̤j��
    power        �P�l���j�p

                        write by Acme@ED  2002.1.29 
*/

#include <ansi.h>

inherit ITEM;

mapping poker=([]);
mapping pok=([]);
mapping p1=([]);
mapping p2=([]);
mapping p3=([]);
mapping p4=([]);
mapping score=(["clear":0,"start":0,"focus":0,"play_kind":0,"owner":"","power":0,"person":0]);
mapping board=(["p1":0,"p2":0,"p3":0,"p4":0]);

/* ���O�禡 */
int do_sit();
int do_reset();
int do_start();
int do_see(string arg);
int do_dump(string arg);
int do_pass();
int do_leave();
int do_rules();
int do_check();
int do_score();

string show_poker(mapping mm,int s);
string show_number(int i);
string show_flower(string str);
string show_score();
string focus_name();
int check_player(string name);    
int check_poker();
int check_over(string name);
void check_board(string winner);
string long();

void create()
{
        set_name("�u�j�ѤG�v �P��", ({ "poker table","table"}));
    set("long", long() );
        set("no_get", 1);
        set("no_box", 1);
        setup();
}

void init()
{
    add_action("do_sit","sit");
    add_action("do_reset","reset");
    add_action("do_start","start");
    add_action("do_see",".");
    add_action("do_dump","du");
    add_action("do_pass","pa");
    add_action("do_check","ch");
    add_action("do_leave","leave");
    add_action("do_rules","rules");
    add_action("do_score",",");
}

int do_sit()
{
    object me=this_player();
    if( score["start"] ) return notify_fail("�P���w�g�}�l�F�C\n");
    if( !check_player(me->query_id()) )
    {
        if( undefinedp(score["p1"]) ) {
            score["p1"]=me->query_id();
            message_vision("$N���W�F�P�઺�_���l�C\n",me);
            board["p1"]=100;
            score["person"]+=1;
        }
        else if( undefinedp(score["p2"]) ) {
            score["p2"]=me->query_id();
            message_vision("$N���W�F�P�઺�F���l�C\n",me);
            board["p2"]=100;
            score["person"]+=1;
        }
        else if( undefinedp(score["p3"]) ) {
            score["p3"]=me->query_id();
            message_vision("$N���W�F�P�઺�n���l�C\n",me);
            board["p3"]=100;
            score["person"]+=1;
        }
        else if( undefinedp(score["p4"]) ) {
            score["p4"]=me->query_id();
            message_vision("$N���W�F�P�઺�����l�C\n",me);
            board["p4"]=100;
            score["person"]+=1;
        }
        else return notify_fail("�P��w�g�����F�C\n");
    }
    else return notify_fail("�A�w�g���b�Ȥl�W�F�C\n");
    return 1;
}

int do_reset()
{
    int i;

    if( !check_poker() )
    {
        message_vision("�§��L�k�~��A$N�N�P�����s�]�w...",this_player());
        score=([]);
    }
    else if( !check_player(this_player()->query_id()) )
        return notify_fail("�A�èS���ѻP�o�����P���C\n");

    /* ���]�ܼ� */
    score["clear"] = 1;
    score["start"] = 0;
    score["focus"] = 0;
    score["power"] = 0;
    score["owner"] = "";
    score["play_kind"] = 0;

    p1=([]);
    p2=([]);
    p3=([]);
    p4=([]);
    poker["m"]=([]);
    poker["f"]=([]);
    poker["h"]=([]);
    poker["t"]=([]);

    /* �] 52 �i�P�A�ó]�w�j�p */
    for(i=1;i<=13;i++)
    {
        if( i == 2 ) {        /* �� 2 �̤j */
            poker["m"][i]=49;
            poker["f"][i]=50;
            poker["h"][i]=51;
            poker["t"][i]=52;
        }
        else if( i == 1 ) {    /* A �ĤG�j */
            poker["m"][i]=45;
            poker["f"][i]=46;
            poker["h"][i]=47;
            poker["t"][i]=48;
        } else {        /* �䥦�P���������j�p */
            poker["m"][i]=i-2+(i-3)*3;
            poker["f"][i]=i-1+(i-3)*3;
            poker["h"][i]=i+(i-3)*3;
            poker["t"][i]=i+1+(i-3)*3;
        }
    }

    message_vision("$N�N�P���s�~�L�@���C\n",this_player());
    return 1;
}

int do_start()
{
    int i, point,value;
    string kind;

    if( !check_player(this_player()->query_id()) )
        return notify_fail("�A�èS���ѻP�o�����P���C\n");

    if( !check_poker() )
        return notify_fail("�H�Ƥ����B�Ϊ̦��P�ͦb�o�b�B�_�u�A�L�k�}�l�C\n");

    if( !score["clear"] ) return notify_fail("�٨S���~�P�C\n");
    if( score["start"] ) return notify_fail("�w�g�}�l�F�C\n");

    /* ���y�o�P */
    point=1;
    for(i=1;i<=52;i++)
    {
        /* ���L�P�ɡA�R����� */
        if( sizeof(poker["m"]) < 1 ) map_delete(poker,"m");
        if( sizeof(poker["f"]) < 1 ) map_delete(poker,"f");
        if( sizeof(poker["h"]) < 1 ) map_delete(poker,"h");
        if( sizeof(poker["t"]) < 1 ) map_delete(poker,"t");
        
        /* �üƨ��P */
        kind=keys(poker)[random(sizeof(keys(poker)))];
        value=keys(poker[kind])[random(sizeof(values(poker[kind])))];
        
        switch( point )
        {
            case 1:
                if( undefinedp(p1[kind]) ) p1[kind]=([]);
                p1[kind][value]=poker[kind][value];
                break;
            case 2:
                if( undefinedp(p2[kind]) ) p2[kind]=([]);
                p2[kind][value]=poker[kind][value];
                break;
            case 3:
                if( undefinedp(p3[kind]) ) p3[kind]=([]);
                p3[kind][value]=poker[kind][value];
                break;
            case 4:
                if( undefinedp(p4[kind]) ) p4[kind]=([]);
                p4[kind][value]=poker[kind][value];
                break;
        }

        map_delete(poker[kind],value);

        if( kind == "m" && value==3 ) {
            score["focus"]=point;
            /* �T�ӤH����W������T�̡A�h�@�i�P */
            if( score["person"]==3 ) point--;
        }
        point++;
        if( score["person"]==3 && point > 3 ) point =1;
        else if( point>4 ) point=1;
    }
    kind=focus_name();
    message_vision(HIW"$N�N�P�~�F�~�A�o�F"+chinese_number(score["person"])+"��... ����T�b"+kind+"��W�A��"+kind+"����X�P�C\n"NOR,this_player());
    score["start"] = 1;
    score["play_kind"] = 7;
    return 1;
}

int do_see(string arg)
{
    if( !check_player(this_player()->query_id()) )
        return notify_fail("�A�èS���ѻP�o�����P���C\n");

    if( !score["start"] ) 
        return notify_fail("�P���٨S�}�l�I\n");

    /* �Ův�@���M�ΡA�����`�n�d�ӫ�������a�I...:P
       ���M�C���򪱮a���������A�Z�����y�H....Hehe....    
     */
    if( arg && !wizardp(this_player()) )
        return notify_fail("�A���ఽ�ݧO�H���P�I\n");
    if( !arg ) arg=this_player()->query_id();

    switch( check_player(arg) )
    {
        case 1:    write( "�i"+score["p1"]+"�j"+show_poker(p1,1) ); break;
        case 2: write( "�i"+score["p2"]+"�j"+show_poker(p2,1) ); break;
        case 3:    write( "�i"+score["p3"]+"�j"+show_poker(p3,1) ); break;
        case 4:    write( "�i"+score["p4"]+"�j"+show_poker(p4,1) ); break;
        default: return notify_fail(arg+"�S���[�J�o�P���C\n"); break;
    }
    return 1;
}

int do_dump(string arg)
{
    int i, len, p, num, d=0;
    string flo;
    mapping p_num=([]), p_flo=([]);

    if( !arg ) return notify_fail("�A�n�����i�P�H\n");

    if( !check_player(this_player()->query_id()) )
        return notify_fail("�A�èS���ѻP�o�����P���C\n");

    if( !score["start"] ) 
        return notify_fail("�P���٨S�}�l�I\n");

    if( (flo=focus_name())=="??" )
        return notify_fail("�o�P���٨S���]�B���٥��o�P�C\n");

    if( flo != this_player()->query_id() )
        return notify_fail("�{�b�O����"+flo+"���P�A�٨S���A�I\n");

    len=strlen(arg);
    if( len > 19 ) return notify_fail("�A��Ӧh�P�F�A�̦h�u��᤭�i�P�I\n");

    /* ����᪺�P */
    for(i=0;i<len;i++)
    if( arg[i..i] == " " || i==len-1 ) {

        if( i!=len-1 ) {
            if( sscanf(arg[p..i-1], "%d%s", num, flo) != 2 )
                return notify_fail("�A�᪺�P�����D�@�I\n");
        } else {
            if( sscanf(arg[p..len], "%d%s", num, flo) != 2 )
                return notify_fail("�A�᪺�P�����D�@�I\n");
        }

        if( num < 1 || num > 13 )
            return notify_fail("�A�᪺�P�j�p���F�I\n");
        if( flo != "t" && flo != "h" && flo != "f" && flo != "m" )
            return notify_fail("�A�᪺�P��⦳���D�@�I\n");

        /* �ˬd�᪺�P���L���� */
        if( !undefinedp(p_flo[flo]) && !undefinedp(p_flo[flo][num]) )
            return notify_fail("�A�᪺�P���ФF�@�I\n");

        /* �P�_�⤤���L���P..&& �N�P���mapping�̡A��K�H��P�_
           && �]�w�j�p
        */
        switch( score["focus"] ) {
            case 1:
                if( undefinedp(p1[flo]) || undefinedp(p1[flo][num]) )
                    return notify_fail("�A��W�S��"+show_flower(flo)+show_number(num)+"�o�i�P�C\n");
                if(undefinedp(p_num[num])) p_num[num]=([]);
                if(undefinedp(p_flo[flo])) p_flo[flo]=([]);
                p_num[num][flo]=p1[flo][num];
                p_flo[flo][num]=p1[flo][num];
                break;
            case 2:
                if( undefinedp(p2[flo]) || undefinedp(p2[flo][num]) )
                    return notify_fail("�A��W�S��"+show_flower(flo)+show_number(num)+"�o�i�P�C\n");
                if(undefinedp(p_num[num])) p_num[num]=([]);
                if(undefinedp(p_flo[flo])) p_flo[flo]=([]);
                p_num[num][flo]=p2[flo][num];
                p_flo[flo][num]=p2[flo][num];
                break;
            case 3:
                if( undefinedp(p3[flo]) || undefinedp(p3[flo][num]) )
                    return notify_fail("�A��W�S��"+show_flower(flo)+show_number(num)+"�o�i�P�C\n");
                if(undefinedp(p_num[num])) p_num[num]=([]);
                if(undefinedp(p_flo[flo])) p_flo[flo]=([]);
                p_num[num][flo]=p3[flo][num];
                p_flo[flo][num]=p3[flo][num];
                break;
            case 4:
                if( undefinedp(p4[flo]) || undefinedp(p4[flo][num]) )
                    return notify_fail("�A��W�S��"+show_flower(flo)+show_number(num)+"�o�i�P�C\n");
                if(undefinedp(p_num[num])) p_num[num]=([]);
                if(undefinedp(p_flo[flo])) p_flo[flo]=([]);
                p_num[num][flo]=p4[flo][num];
                p_flo[flo][num]=p4[flo][num];
                break;
        }    
        d++;
        p=i+1;
    }
        
    /* �P���@�}�l������X����T */
    if( score["play_kind"]==7 && ( undefinedp(p_flo["m"]) || undefinedp(p_flo["m"][3]) ) )
        return notify_fail("�P���@�}�l������X����T�C\n");

    if( score["owner"] == this_player()->query_id() ) {
        score["power"] = 0;
        score["play_kind"] = 0;
    }

    switch( d ) {
        case 1: /* �m�� */
            if( score["play_kind"] != 1 && score["play_kind"] != 0 && score["play_kind"] != 7 )
                return notify_fail("�{�b���O�m�檺�ɭԡC\n");

            /* check power */
            p=0;
            foreach( flo in keys(p_flo) )
            foreach( i in keys(p_flo[flo]) )
                p=p_flo[flo][i];
            if( p < score["power"] ) 
                return notify_fail("�A�᪺�P�����j�@�I\n");

            score["play_kind"] = 1;
            score["power"]=p;
            message_vision("$N���D�G"HIW"�u "NOR+YEL"�m��I"HIW"�v"NOR"\n",this_player());
            break;

        case 2: /* ��l */
            if( score["play_kind"] != 2 && score["play_kind"] != 0 && score["play_kind"] != 7 )
                return notify_fail("�{�b���O���l���ɭԡC\n");

            /* check�O�_����l */
            if( sizeof( keys(p_num) ) > 1 )
                return notify_fail("��G�i�P�ɡA���ݥ��l�~��C\n");

            /* check power */
            p=0;
            foreach( flo in keys(p_flo) )
            foreach( i in keys(p_flo[flo]) )
                if( p < p_flo[flo][i] ) p=p_flo[flo][i];
            if( p < score["power"] ) 
                return notify_fail("�A�᪺��l�����j�@�I\n");
            score["play_kind"] = 2;
            score["power"]=p;
            message_vision("$N���D�G"HIW"�u "NOR+MAG"��l�I"HIW"�v"NOR"\n",this_player());
            break;

        case 3: return notify_fail("�S���o�زզX���P�@�C\n"); break;
        case 4:    return notify_fail("�S���o�زզX���P�@�C\n"); break;

        case 5: 
            num=sizeof(keys(p_num));
            /* ���l�B�P�ᶶ */
            if( num == 5) {
                int *check, x, y, swap;
                check=keys(p_num);

                /* �Ƨ� */
                    for(x=4;x>0;x--)
                        for(y=1;y<=x;y++)
                if( check[y-1] < check[y] )
                {
                    swap=check[y-1];
                    check[y-1]=check[y];
                    check[y]=swap;
                        }
                
                /* check�O�_�����l,1 10,11,12,13 �]�O���l */
                if( check[0]!=13 || check[1]!=12 || check[2]!=11 || check[3]!=10 || check[4]!=1 ) {
                    y=check[0];
                    for(x=1;x<5;x++) {
                        if( y-check[x] != 1 )
                            return notify_fail("�S���o�زզX���P�a�H(5)\n");
                        y=check[x];
                    }
                }

                /* check power 1~5�̤p */
                if( check[0]==5 && check[1]==4 && check[2]==3 && check[3]==2 && check[4]==1 ) {
                    foreach( flo in keys(p_num[5]) )
                        p=p_num[5][flo];
                } else {
                    p=0;
                    foreach( flo in keys(p_flo) )
                    foreach( i in keys(p_flo[flo]) )
                        if( p < p_flo[flo][i] ) p=p_flo[flo][i];
                }

                /* check �O�_�P�� */
                num=0;
                foreach( flo in keys(p_flo) )
                if( num < sizeof(keys(p_flo[flo])) ) num = sizeof(keys(p_flo[flo]));

                if( num==5 ) {
                    if( score["play_kind"] == 6 && p < score["power"] )
                        return notify_fail("�A�᪺�P�ᶶ�����j�@�I\n");
                    score["play_kind"]=6;
                    message_vision("$N�g���D�G"HIW"�u "HIY"�z�I���I���I�P�ᶶ�I"HIW"�v"NOR"\n",this_player());
                } else {
                    if( score["play_kind"] != 4 && score["play_kind"] != 0 && score["play_kind"] != 7 )
                        return notify_fail("�{�b���O�X���l���ɭԡC\n");
                    if( p < score["power"] ) 
                        return notify_fail("�A�᪺���l�����j�@�I\n");
                    score["play_kind"]=4;
                    message_vision("$N�s�D�G"HIW"�u "HIM"���l�I"HIW"�v"NOR"\n",this_player());
                }
                score["power"]=p;

            /* �K��B��Ī */
            } else if( num == 2 ) {
                i=0; len=0; p=0;
                foreach( num in keys(p_num) )
                if( i < sizeof(keys(p_num[num])) ) {
                    i=sizeof(keys(p_num[num]));
                    len=num;
                }

                /* ��Ī */
                if( i == 3 ) {
                    if( score["play_kind"] != 3 && score["play_kind"] != 0 && score["play_kind"] != 7 )
                        return notify_fail("�{�b���O�X��Ī���ɭԡC\n");
                    foreach( flo in keys(p_num[len]) )
                        if( p < p_num[len][flo] ) p = p_num[len][flo];
                    if( score["power"] > p )
                        return notify_fail("�A�᪺��Ī�����j�@�I\n");
                    score["play_kind"]=3;
                    message_vision("$N�۹D�G"HIW"�u "HIG"��Ī�I"HIW"�v"NOR"\n",this_player());
                /* �K�� */
                } else if( i==4 ) {
                    if( score["play_kind"] == 6 )
                        return notify_fail("�{�b���O�X�K�䪺�ɭԡC\n");
                    foreach( flo in keys(p_num[len]) )
                        if( p < p_num[len][flo] ) p = p_num[len][flo];
                    if( score["play_kind"] == 5 && score["power"] > p )
                        return notify_fail("�A�᪺�K�䤣���j�@�I\n");
                    score["play_kind"]=5;
                    message_vision("$N�j�n���D�G"HIW"�u "HIC"���I���I�K��I"HIW"�v"NOR"\n",this_player());

                } else return notify_fail("�A�X���P�զX�����D�@�C\n");

                score["power"]=p;

            } else return notify_fail("�S���o�زզX���P�@�C\n"); break;

            break;
        default: return notify_fail("�A�᪺�P�Ӧh�i�F�A�̦h���i�C\n"); break;
    }

    pok=p_flo;
    /* ��X���P�q�⤤�M�� */
    foreach( flo in keys(p_flo) )
    foreach( i in keys(p_flo[flo]) )
    switch( score["focus"] )
    {
        case 1: map_delete(p1[flo],i); break;
        case 2: map_delete(p2[flo],i); break;
        case 3: map_delete(p3[flo],i); break;
        case 4: map_delete(p4[flo],i); break;
    }
    score["owner"]=this_player()->query_id();

    message_vision(show_poker(p_flo,0),this_player());

    if( !check_over(this_player()->query_id()) ) {
        score["focus"] += 1;
        if( score["person"]==3 && score["focus"] > 3 ) score["focus"]=1;
        else if( score["focus"] > 4 ) score["focus"]= 1;
        message_vision("... ����"+focus_name()+"���P�C\n",this_player());
    } else {
        message_vision("\n$N�o�F�g�믺�D�G"HIW"�u "HIY"�f�c�I�f�X�I�f�X�I�f�X�I ��  Ĺ  �F�I�I�I"HIW"�v\n\n"NOR,this_player());

        check_board(this_player()->query_id());
        do_reset();
    }

    return 1;
}

int do_pass()
{
    string who;
    object me=this_player();

    if( !check_player(me->query_id()) )
        return notify_fail("�A�èS���ѻP�o�����P���C\n");

    if( !score["start"] ) 
        return notify_fail("�P���٨S�}�l�I\n");

    if( (who=focus_name())=="??" )
        return notify_fail("�o�P���٨S���]�B���٥��o�P�C\n");

    if( who != me->query_id() )
        return notify_fail("�{�b�O����"+who+"���P�A�٨S���A�I\n");

    if( score["play_kind"]==7 )
        return notify_fail("�{�b�_�X�n��@�i����T�A����Pass�@�C\n");

    if( score["owner"] == me->query_id() )
        return notify_fail("�A�����Pass�A�A�N�H�K��X�i�P�a�C\n");

    score["focus"] += 1;
    if( score["person"] == 3 && score["focus"] > 3 )  score["focus"]=1;
    else if( score["focus"] > 4 ) score["focus"]= 1;

    message_vision("$N�j�n���D�G"HIW"�y "HIY"�ޢ�����I"HIW"�z"NOR"... ����"+focus_name()+"���P�C\n",me);
    return 1;
}


int do_check()
{
    string msg;
    
    if( !check_player(this_player()->query_id()) )
        return notify_fail("�A�èS���ѻP�o�����P���C\n");

    if( !score["start"] ) 
        return notify_fail("�P���٨S�}�l�I\n");

    if( focus_name()=="??" )
        return notify_fail("�o�P���٨S���]�B���٥��o�P�C\n");

    if( sizeof(pok) < 1 )
        return notify_fail("�ثe�ୱ�W�S���P�I\n");

    msg = "��"+score["owner"]+"�ҥX���P�G";
    msg += show_poker(pok,0);
    msg += "���U�Ӵ�"+focus_name()+"�X�P�C\n";
    write(msg);
    return 1;
}

int do_leave()
{
    object me=this_player();

    if( !check_player(me->query_id()) )
        return notify_fail("�A�èS���ѻP�o�����P���C\n");

    if( score["p1"] == me->query_id() ) 
        map_delete(score,"p1");
    else if( score["p2"] == me->query_id() )
        map_delete(score,"p2");
    else if( score["p3"] == me->query_id() )
        map_delete(score,"p3");
    else {
        if( undefinedp(score["p4"]) ) return 0;
        if( score["p4"] == me->query_id() )
        map_delete(score,"p4");
    }

    message_vision("$N���}�F�P�ण���F�C\n",me);
    score["person"]-=1;
    if( score["start"] ) do_reset();
    return 1;
}
int do_rules()
{
    write(@rules
    ����������������������������������������������������������
    ��               ��J�P-�j�ѤG �C���W�h����            ��
    ����������������������������������������������������������
    ��  �j�a�����D�F... �i�o���F ccc..                      ��
    ��                                                      ��
    ��  �ݭn�`�N���O�G                                      ��
    ��       �@�B�S���u�R�A�v                               ��
    ��       �G�B�S���u�T���v                               ��
    ��       �T�B���l1~5�O�̤p��                            ��
    ��       �|�B�u�n�䤤�@�Ӫ��̤⤤�S�P�YĹ�F             ��
    ��       ���B�T�ӤH�]�i�H���A�⤤������T���H�h�@�i�P   ��
    ��                                                      ��
    ��  �p���覡�G                                          ��
    ��       ���P��������A�⤤�ѴX�i�P�N���X�I����         ��
    ��       �p�G�W�L�Q�i�h���G�A�p�G���j�ѤG�]���G         ��
    ��       �䥦�H�����I�ƫh�[��Ĺ���H�C                   ��
    ��                                                      ��
    ��                             write by -Acme@ED-       ��
    ����������������������������������������������������������
rules);

    return 1;
}

int do_score()
{
    if( !score["start"] ) 
        return notify_fail("�P���٨S�}�l�I\n");

    if( focus_name()=="??" )
        return notify_fail("�o�P���٨S���]�B���٥��o�P�C\n");

    write(show_score()+"\n");

    return 1;
}

/* ��ܥثe�X�P�H���W�r */
string focus_name()
{
    if( undefinedp(score["focus"]) ) return "??";
    switch( score["focus"] )
    {
        case 1: if( !undefinedp(score["p1"]) ) return score["p1"]; break;
        case 2: if( !undefinedp(score["p2"]) ) return score["p2"]; break;
        case 3: if( !undefinedp(score["p3"]) ) return score["p3"]; break;
        case 4: if( !undefinedp(score["p4"]) ) return score["p4"]; break;
    }
    return "??";
}

/* ��ܤ�W���P */
string show_poker(mapping mm,int s)
{
    int i, t;
    string msg="", msg2="",bar_up,bar_down, num;

    t=sizeof(mm["t"])+sizeof(mm["h"])+sizeof(mm["f"])+sizeof(mm["m"])-1;
    bar_up = "\n��";
    bar_down = "��";
    while( t-- ) {
        bar_up += "����";
        bar_down += "����";
    }
    bar_up += "����\n";
    bar_down += "����\n";

    /* ���Ӥj�p�ƦC */
    for(i=13;i>0;i--)
    {
        num=show_number(i);
        if( member_array("t",keys(mm))!=-1 && !undefinedp(mm["t"][i]) ) {
            msg+=sprintf("��%s",num);
            msg2+="��"+HIK"��"NOR;
        }
        if( member_array("h",keys(mm))!=-1 && !undefinedp(mm["h"][i]) ) {
            msg+=sprintf("��%s",num);
            msg2+="��"+HIR"��"NOR;
        }
        if( member_array("f",keys(mm))!=-1 && !undefinedp(mm["f"][i]) ) {
            msg+=sprintf("��%s",num);
            msg2+="��"+HIR"��"NOR;
        }
        if( member_array("m",keys(mm))!=-1 && !undefinedp(mm["m"][i]) ) {
            msg+=sprintf("��%s",num);
            msg2+="��"+HIK"��"NOR;
        }
    }
    if( s ) {
        msg+="��\tt->"HIK"�®�"NOR", h->"HIR"����"NOR"\n";
        msg2+="��\tf->"HIR"���"NOR", m->"HIK"����"NOR"\n";
    }
    else {
        msg+="��\n";
        msg2+="��\n";
    }
    return bar_up+msg+msg2+bar_down;
}

/* �q�Ʀr */
string show_number(int i)
{
    switch( i ) {
        case 1: return "��"; break;
        case 2: return HIW"��"NOR; break;
        case 3: return "��"; break;
        case 4: return "��"; break;
        case 5: return "��"; break;
        case 6: return "��"; break;
        case 7: return "��"; break;
        case 8: return "��"; break;
        case 9: return "��"; break;
        case 10: return "10"; break;
        case 11: return "��"; break;
        case 12: return "��"; break;
        case 13: return "��"; break;
    }
    return "??";
}

/* �q��� */
string show_flower(string str)
{
    switch( str ) {
        case "t": return "�®�"; break;
        case "h": return "����"; break;
        case "f": return "���"; break;
        case "m": return "����"; break;
    }
    return "??";
}

string show_score()
{
    string msg="";

    if( !undefinedp(board["p1"]) && !undefinedp(score["p1"]) )
        msg+=score["p1"]+"�ثe��"+board["p1"]+"��  ";

    if( !undefinedp(board["p2"]) && !undefinedp(score["p2"]) )
        msg+=score["p2"]+"�ثe��"+board["p2"]+"��  ";

    if( !undefinedp(board["p3"]) && !undefinedp(score["p3"]) )
        msg+=score["p3"]+"�ثe��"+board["p3"]+"��  ";

    if( !undefinedp(board["p4"]) && !undefinedp(score["p4"]) )
        msg+=score["p4"]+"�ثe��"+board["p4"]+"��  ";

    return msg;
}

/* �ˬd�O�_���b�P��e */
int check_player(string name)
{
    if( name == score["p1"] ) return 1;
    else if( name == score["p2"] ) return 2;
    else if( name == score["p3"] ) return 3;
    else {
        if( undefinedp(score["p4"]) ) return 0;
        if( name == score["p4"] ) return 4;
    }
    return 0; 
}

/* �ˬd�P���O�_�i�H�~����� */
int check_poker()
{
    object user;
    if( !undefinedp(score["p1"]) && 
        /* ���a���}�B�_�u�εo�b�A�L�k�i�� */
        user = present(score["p1"], environment(this_object()))) {
        if(!interactive(user)) return 0;
        if(query_idle(user) > 180) return 0;
    }
    else return 0;

    if( !undefinedp(score["p2"]) && 
        user = present(score["p2"], environment(this_object()))) {
        if(!interactive(user)) return 0;
        if(query_idle(user) > 180) return 0;
    }
    else return 0;

    if( !undefinedp(score["p3"]) && 
        user = present(score["p3"], environment(this_object()))) {
        if(!interactive(user)) return 0;
        if(query_idle(user) > 180) return 0;
    }
    else return 0;

    /* �T�H�]�i�� */
    if( score["person"] == 3 ) return 1;
    if( !undefinedp(score["p4"]) && 
        user = present(score["p4"], environment(this_object()))) {
        if(!interactive(user)) return 0;
        if(query_idle(user) > 180) return 0;
    }
    else return 0;
    return 1;
}

/* �ˬd�P���O�_���� */
int check_over(string name)
{
    int i;
    i=check_player(name);
    switch( i )
    {
        case 1: if( sizeof(p1["m"]) < 1 && sizeof(p1["f"]) < 1 
            && sizeof(p1["h"]) < 1 && sizeof(p1["t"]) < 1 ) return 1; break;
        case 2: if( sizeof(p2["m"]) < 1 && sizeof(p2["f"]) < 1 
            && sizeof(p2["h"]) < 1 && sizeof(p2["t"]) < 1 ) return 1; break;
        case 3: if( sizeof(p3["m"]) < 1 && sizeof(p3["f"]) < 1 
            && sizeof(p3["h"]) < 1 && sizeof(p3["t"]) < 1 ) return 1; break;
        case 4: 
            if( undefinedp(score["p4"]) ) return 0;
            if( sizeof(p4["m"]) < 1 && sizeof(p4["f"]) < 1 
            && sizeof(p4["h"]) < 1 && sizeof(p4["t"]) < 1 ) return 1; break;
    }
    return 0;
}

void check_board(string winner)
{
    int num=0, x, i;
    string flo;
    object me=this_player();

    message_vision("����������������������������������������������������������������������\n",me);
    message_vision("                              ��      ��                              \n",me);
    message_vision("����������������������������������������������������������������������\n",me);
    i=x=0;
    if( winner != score["p1"] ) {
        message_vision(score["p1"]+"�⤤�ҳѤU���P�G"+show_poker(p1,0),me);
        foreach( flo in keys(p1) ) {
            i+=sizeof(keys(p1[flo]));
            if( !undefinedp(p1[flo][2]) ) {
                message_vision(show_flower(flo)+"������(x2) ",me);
                x+=2;
            }
        }
        if( i > 9 ) {
            message_vision("�ѤU���P�W�L�Q�i(x2)�C",me);
            x+=2;
        }
        if( !x ) x=1;
        message_vision(score["p1"]+"�`�@���F"+i+"*"+x+"="+i*x+"�I���ơC\n",me);
        i=i*x;
        board["p1"]-=i;
        num+=i;
        message_vision("\n\n",me);
    }

    i=x=0;
    if( winner != score["p2"] ) {
        message_vision(score["p2"]+"�⤤�ҳѤU���P�G"+show_poker(p2,0),me);
        foreach( flo in keys(p2) ) {
            i+=sizeof(keys(p2[flo]));
            if( !undefinedp(p2[flo][2]) ) {
                message_vision(show_flower(flo)+"������(x2) ",me);
                x+=2;
            }
        }
        if( i > 9 ) {
            message_vision("�ѤU���P�W�L�Q�i(x2)�C",me);
            x+=2;
        }
        if( !x ) x=1;
        message_vision(score["p2"]+"�`�@���F"+i+"*"+x+"="+i*x+"�I���ơC\n",me);
        i=i*x;
        board["p2"]-=i;
        num+=i;
        message_vision("\n\n",me);
    }

    i=x=0;
    if( winner != score["p3"] ) {
        message_vision(score["p3"]+"�⤤�ҳѤU���P�G"+show_poker(p3,0),me);
        foreach( flo in keys(p3) ) {
            i+=sizeof(keys(p3[flo]));
            if( !undefinedp(p3[flo][2]) ) {
                message_vision(show_flower(flo)+"������(x2) ",me);
                x+=2;
            }
        }
        if( i > 9 ) {
            message_vision("�ѤU���P�W�L�Q�i(x2)�C",me);
            x+=2;
        }
        if( !x ) x=1;
        message_vision(score["p3"]+"�`�@���F"+i+"*"+x+"="+i*x+"�I���ơC\n",me);
        i=i*x;
        board["p3"]-=i;
        num+=i;
        message_vision("\n\n",me);
    }

    i=x=0;
    if( !undefinedp(score["p4"]) && winner != score["p4"] ) {
        message_vision(score["p4"]+"�⤤�ҳѤU���P�G"+show_poker(p4,0),me);
        foreach( flo in keys(p4) ) {
            i+=sizeof(keys(p4[flo]));
            if( !undefinedp(p4[flo][2]) ) {
                message_vision(show_flower(flo)+"������(x2) ",me);
                x+=2;
            }
        }
        if( i > 9 ) {
            message_vision("�ѤU���P�W�L�Q�i(x2)�C",me);
            x+=2;
        }
        if( !x ) x=1;
        message_vision(score["p4"]+"�`�@���F"+i+"*"+x+"="+i*x+"�I���ơC\n",me);
        i=i*x;
        board["p4"]-=i;
        num+=i;
        message_vision("\n\n",me);
    }

    if( score["p1"] == winner ) {
        message_vision(HIY+score["p1"]+"Ĺ�F�o���A�@�o"+num+"���C\n"NOR,me);
        board["p1"]+=num;
    } else if( score["p2"] == winner ) {
        message_vision(HIY+score["p2"]+"Ĺ�F�o���A�@�o"+num+"���C\n"NOR,me);
        board["p2"]+=num;
    } else if( score["p3"] == winner ) {
        message_vision(HIY+score["p3"]+"Ĺ�F�o���A�@�o"+num+"���C\n"NOR,me);
        board["p3"]+=num;
    } else if( !undefinedp(score["p4"]) && score["p4"] == winner ) {
        message_vision(HIY+score["p4"]+"Ĺ�F�o���A�@�o"+num+"���C\n"NOR,me);
        board["p4"]+=num;
    }
    message_vision("����������������������������������������������������������������������\n",me);
    message_vision(show_score()+"\n",me);
    message_vision("����������������������������������������������������������������������\n",me);

    return;
}

string long()
{
    string msg="";
        
    msg += "����������������\n";
    msg += "�� �j�ѤG�P�� ��\n";
    msg += "��������������������������������������������������������������������\n";
    msg += "��                                ��                              ��\n";
    msg += "��     rules     �[�ݳW�h         ��                              ��\n";
    msg += "��     leave     ���}�P��         ��                              ��\n";
    msg += sprintf("��     sit     ��y�짤         ��%13s%-17s��\n","",
            !undefinedp(score["p1"]) ? score["p1"] : "" );

    msg += "��     reset     �]�m�s���B�~�P   ��            ������            ��\n";

    msg += sprintf("��     start     �}�l�P��         ��%12s������%-12s��\n",
            !undefinedp(score["p4"]) ? score["p4"] : "",
            !undefinedp(score["p2"]) ? score["p2"] : "" );

    msg += "��     .         �[�ݤ⤤���P     ��            ������            ��\n";

    msg += sprintf("��     du     ��P             ��%13s%-17s��\n","",
            !undefinedp(score["p3"]) ? score["p3"] : "" );

    msg += "��     pa        �X�P�v�����U�a   ��                              ��\n";
    msg += "��     ch        �˵��ثe�O����P ��                              ��\n";
    msg += "��     ,         �˵��ثe����      ��                              ��\n";
    msg += "��                                ��                              ��\n";
    msg += "��������������������������������������������������������������������\n";
    msg += "��     �®�Ot, ���߬Oh, ����Of, ����Om                         ��\n";
    msg += "��     �Ѣ٬O13, �߬O12, �جO11, �ϬO1                            ��\n";
    msg += "��     du�ɬ�du 10t 3h, ��h�i�P�ɥH�ťչj�}                      ��\n";
    msg += "��     ���i�HK,Q,J,A�覡��A�����O�Ʀr�~��                        ��\n";
    msg += "��������������������������������������������������������������������\n";

    return msg;
}