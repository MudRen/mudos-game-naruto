/*  who.c write by -Acme-
*/

#include <ansi.h>

inherit F_CLEAN_UP;

object *all, *target;
string msg;
int i, j;

void msg_format(string arg);

void create() { seteuid(getuid()); }

mixed main(object me, string arg, int remote)
{
    int center_lv;
    string tmp;
    target = ({});
    msg = "";

    /* ���L�o�|���n�J�������ϥΪ̡A�P���Ϊ��W�ŧŮv�C
     * �`�N�b�Q rwho_q �I�s�����p�U�Athis_player() �� 0�C
     */
    if( this_player(1) )
        all = filter(users(), (: objectp(environment($1)) &&
                                 (!wizardp($1) || wiz_level($2)>wiz_level($1) || $1->visible($2)) :), this_player(1));
    else all = filter(users(), (: objectp(environment($1)) && !wizardp($1) :));

    i = sizeof(all);
    
    if( !arg || arg=="" ) {
	    center_lv = me->query_level();
        while( i-- ) {
            if( all[i]->query_level() - center_lv < 6 && center_lv - all[i]->query_level() < 6 && !wizardp(all[i]) )
                target += ({ all[i] });
        }
        msg_format("1");
    } else {
        switch(arg){
            case "-mu":
        		target = filter(all, (: $1->query("guild")=="muye" :));     // �츭��
                msg_format("5");
                break;
            case "-yi":
        		target = filter(all, (: $1->query("guild")=="yinyin" :));   // ������
                msg_format("5");
                break;
            case "-wn":
        		target = filter(all, (: $1->query("guild")=="wuyin" :));    // ������
                msg_format("5");
                break;
            case "-sn":
        		target = filter(all, (: $1->query("guild")=="shayin" :));   // ������
                msg_format("5");
                break;
            case "-yn":
        		target = filter(all, (: $1->query("guild")=="yuyin" :));    // �B����
                msg_format("5");
                break;
            case "-yy":
        		target = filter(all, (: $1->query("guild")=="yunyin" :));   // ������
                msg_format("5");
                break;
            case "-cn":
        		target = filter(all, (: $1->query("guild")=="caoyin" :));   // ������
                msg_format("5");
                break;
            case "-pn":
        		target = filter(all, (: $1->query("guild")=="puyin" :));    // �r����
                msg_format("5");
                break;
        	case "-cr":
        		target = filter(all, (: $1->query_class()=="commoner" :));  // ����
                msg_format("5");
        		break;
            case "-ir":
                target = filter(all, (: $1->query_class()=="inferior" :));  // �U��
                msg_format("5");
                break;
            case "-me":
                target = filter(all, (: $1->query_class()=="middle" :));    // ����
                msg_format("5");
                break;
            case "-sr":
                target = filter(all, (: $1->query_class()=="superior" :));  // �W��
                msg_format("5");
                break;
            case "-an":
                target = filter(all, (: $1->query_class()=="assassin" :));  // �t��
                msg_format("5");
                break;
            case "-pe":
                target = filter(all, (: $1->query_class()=="police" :));    // ĵ��
                msg_format("5");
                break;
            case "-mh":
                target = filter(all, (: $1->query_class()=="monarch" :));   // �v��
                msg_format("5");
                break;
            case "-h":
                target = filter(all, (: $1->query("guild")=="hunter" :));   // �y�H
                msg_format("5");
                break;
            case "-l":
                target = all;
                msg_format("5");
                break;
            case "-w":
	            target = filter(all, (: wizardp :));
                msg_format("5");
                break;
            case "-i":
                msg_format("41");
                break;
            case "-n":
                msg_format("42");
                break;
	        default :
	            return notify_fail("�п�J help who �F�ѫ��O�榡�C\n");
        }
    }

    tmp = msg;
//    tmp += sprintf("�x�@�C�X %3d/%3d ��ϥΪ�  �t�έt���G%-37s�x\n",  sizeof(target), sizeof(all), query_load_average());
    tmp += sprintf("�x%-72s�x\n", "�@�C�X " + sizeof(target) + "/" + sizeof(all) + " ��ϥΪ�  �t�έt���G" + query_load_average());
    tmp += "���w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��";
    
    if( remote ) return tmp;

    me->start_more(tmp);
    return 1;
}

int sort_user(object ob1, object ob2)
{
    int ord;

    ord = wiz_level(ob1) - wiz_level(ob2);
    if( ord==0 )
        ord = (int)ob1->query_level() - (int)ob2->query_level();
    if( ord == 0 )
        ord = ob1->query_score("combat exp") - ob2->query_score("combat exp");
    return ord;
}

void msg_format(string arg)
{
	string tmp, ntmp;
    if( !arg || arg=="" )    return;

    j = sizeof(target);
    target = sort_array(target, "sort_user", this_object());

    switch(arg){
    case "1":
    case "5":
    case "50":
        msg  = "�~�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n";
        msg += sprintf("�x%-72s�x\n", MUD_NAME+"�u�W���a�C��" );
        msg += "�u�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�t\n";
        msg += "�x"BYEL"����"NOR" "BRED"  ¾    �~  "NOR" "BGRN"  �Y      ��  "NOR" "BMAG"  ��      ��  "NOR" "BBLU"        �W��(ID)        "NOR"�x\n";

        while( j-- ) {
        	if( target[j]->query("nickname") ) ntmp = uncolor(target[j]->query("nickname"));
        	else ntmp = "";
            tmp = sprintf("�x%|4d %s%|12s"NOR" %|14s %|14s %12s%-12s�x\n"NOR,
                  target[j]->query_level(),
                  wizardp(target[j]) ? BOLD : NOR,
                  target[j]->rank(),
                  target[j]->query("title") ? target[j]->query("title") : "",
                  ntmp,
                  target[j]->query("name", 1),
                  "(" + capitalize(target[j]->query("id")) + ")" );
            if( ntmp != "" ) tmp = replace_string(tmp, ntmp, target[j]->query("nickname"));
            msg += tmp;
/*
            msg = sprintf("%s�x%|4d %s%|12s"NOR" %|14s %|14s %12s%-12s�x\n"NOR,
                  msg,
                  target[j]->query_level(),
                  wizardp(target[j]) ? BOLD : NOR,
                  target[j]->rank(),
                  target[j]->query("title") ? target[j]->query("title") : "",
                  target[j]->query("nickname") ? target[j]->query("nickname") : "",
                  target[j]->query("name", 1),
                  "(" + capitalize(target[j]->query("id")) + ")" );
*/
        }
        msg += "�u�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�t\n";

        break;
    case "41":
        target = sort_array(all, "sort_user", this_object());
        j = sizeof(target);
        msg  = "�~�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n";
        msg += sprintf("�x%-72s�x\n", MUD_NAME+"�u�W���a�C��" );
        msg += "���w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n";

        while( j-- ) {
            msg = sprintf("%s  %-10s%s", msg, capitalize(target[j]->query("id")), (( i - j ) % 6 ) ? "" : "\n" );
        }
        if( i % 6 ) msg += "\n";
        msg += "�~�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n";
        break;
    case "42":
        target = sort_array(all, "sort_user", this_object());
        j = sizeof(target);
        msg  = "�~�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n";
        msg += sprintf("�x%-72s�x\n", MUD_NAME+"�u�W���a�C��" );
        msg += "���w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n";
        while( j-- ) {
            msg = sprintf("%s  %-12s%s", msg, target[j]->query("name", 1), (( i - j ) % 6 ) ? "" : "\n" );
        }
        if( i % 6 ) msg += "\n";
        msg += "�~�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n";
        break;
    default:
        msg = "�п�J help who �F�ѫ��O�榡�C\n";
    }
}

int help(object me)
{
    write(@HELP
���O�榡 : who [�ﶵ]

�o�ӫ��O�i�H�C�X�b�u�W���ϥΪ̤Ψ䵥��������T�C
�ﶵ���U�C�X��, �@���u�i�ϥΤ@�ؿﶵ, �Y who -i -w ���P who -i�C
�L�ﶵ��, �C�X�P�A���Ŭۮt 5 �ťH�����ϥΪ̡C

�@��ﶵ�G
  -w  �u�C�X�Ův                     -l  �C�X�Ҧ��ϥΪ�
  -n  �u�C�X����W��                 -i  �u�C�X�^��ID

¾�~�ﶵ�G
  -cr �C�X�Ҧ�����(commoner)         -ir �C�X�Ҧ��U��(inferior)
  -me �C�X�Ҧ�����(middle)           -sr �C�X�Ҧ��W��(superior)
  -an �C�X�Ҧ��t��(assassin)         -pe �C�X�Ҧ�ĵ��(police)
  -mh �C�X�Ҧ��v��(monarch)

  -h �C�X�Ҧ��y�H

�Ԫ̧��ﶵ�G
  -mu �C�X�Ҧ��츭���Ԫ�(muye)       -yi �C�X�Ҧ��������Ԫ�(yinyin)
  -wn �C�X�Ҧ��������Ԫ�(wuyin)      -sn �C�X�Ҧ��������Ԫ�(shayin)
  -yn �C�X�Ҧ��B�����Ԫ�(yuyin)      -yy �C�X�Ҧ��������Ԫ�(yunyin)
  -cn �C�X�Ҧ��������Ԫ�(caoyin)     -pn �C�X�Ҧ��r�����Ԫ�(puyin)

�������O�G finger
HELP);
    return 1;
}
