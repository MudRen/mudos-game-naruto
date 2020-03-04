/* skills.c */

#include <ansi.h>
#include <skill.h>

inherit F_CLEAN_UP;

string *skill_level_desc = ({
    "��ǥE�m",
    "�ʳq�֤�",
    "�����Ү�",
    "�b�ͤ���",
    "�������",
    "�w���p��",
    "���m�p�N",
    "���x�ۦp",
    "�r���N��",
    "�X���޵�",
    "�������Z",
    "���G���",
    "�l���«C",
    "�X���J��",
    "�n�p�y��",
    "�W�����j",
    "�W�Z�J�t",
    "��\�k�u",
    "�`���i��"
});

string *knowledge_level_desc = ({
    "�s�ǥE��",
    "��s���|",
    "�����@�G",
    "�������",
    "�w���p��",
    "�o������",
    "���M����",
    "�߻⯫�|",
    "�W���ѤU",
    "�@�N�v�v",
    "�`���i��"
});

string skill_level(string, int);

mapping _skill;
object ob;

string skill_class(string sk)
{
    switch( SKILL_D(sk)->query_class() ) {
        // naruto
        case "force": return BRED"��N"NOR; break;
        case "ninja": return BBLU"�ԳN"NOR; break;

        // hunter
        case "psychical": return BWHT+BLK"����"NOR; break;
        case "concrete":  return BRED"��{"NOR; break;
        case "emit":      return BGRN"��X"NOR; break;
        case "operation": return BYEL"�ާ@"NOR; break;
        case "special":   return BBLU"�S��"NOR; break;
        case "strength":  return BMAG"�j��"NOR; break;
        case "variation": return BCYN"�ܤ�"NOR; break;

        // piece
        case "fruit":    return HIY"�G��"NOR; break;
        case "blade":    return BGRN"�M�N"NOR; break;
        case "spurn":    return BYEL"���"NOR; break;
        case "martial":  return BRED"�Z�N"NOR; break;
        case "activity": return REV"�S��"NOR; break;

        case "basic": return HIW"��"NOR; break;
        default: return HIK"�䥦"NOR; break;
    }
}

string skill_ability(int i)
{
    switch( i ) {
        case 10: return HIW"[S]"NOR; break;
        case  9:
        case  8: return HIY+"["+i+"]"+NOR;break;
        case  7:
        case  6: return HIC+"["+i+"]"+NOR;break;
        case  5:
        case  4: return HIG+"["+i+"]"+NOR;break;
        case  3: 
        case  2:
        default: return HIK+"["+i+"]"+NOR;break;
}
}

int sk_sort(string sk1, string sk2)
{
    if( !SKILL_D(sk2)->query_class() || !SKILL_D(sk1)->query_class() )
        return ob->query_skill(sk2) - ob->query_skill(sk1);
    if( strcmp(SKILL_D(sk2)->query_class(), SKILL_D(sk1)->query_class()) == 0)
        return ob->query_skill(sk2) - ob->query_skill(sk1);
    else return strcmp(SKILL_D(sk2)->query_class(), SKILL_D(sk1)->query_class());
}

int main(object me, string arg)
{
//    object ob;
    mapping skl, lrn, map, flag, ability, require;
    string *sname, *mapped, s, old_s, line, option;
    int show_all = 0;

    seteuid(getuid());

    if( !arg )  ob = me;
    else {
        if( arg == "-clear" ) {
            me->clear_flags();
            write("ok\n");
            return 1;
        }
        
        ob = present(arg, environment(me));
        if (!ob) ob = find_player(arg);
        if (!ob) ob = find_living(arg);
        if (!ob) return notify_fail("�A�n��ݽ֪��ޯ�S\n");
        if( !wizardp(me)
         && !ob->is_apprentice_of(me)
         && !me->is_apprentice_of(ob)
         && !ob->accept_info(me, "skills") )
                return notify_fail("�u���Ův�Φ��v�{���Y���H���ݥL�H���ޯ�C\n");
    }

    flag = ob->query_skill_flags();
    if( !mapp(flag) ) flag = ([]);

    skl = ob->query_skills();
    if( !mapp(skl) ) skl = ([]);

    lrn = ob->query_learned();
    if( !mapp(lrn) ) lrn = ([]);

    ability = ob->query_skills_ability();
    if( !mapp(ability) ) ability = ([]);

    require = ob->query_skills_require();
    if( !mapp(require) ) require = ([]);

    if(!sizeof(skl) && !sizeof(lrn)) {
        write( (ob==me ? "�A" : ob->name()) + "�ثe�èS���Ƿ|����ޯ�C\n");
        return 1;
    }

    line = "�~�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n";
    line += sprintf("�x%-72s�x\n", (ob==me ? "�A" : ob->name()) + "�ثe�Ҳ߱o���ޯ�C��");

    // This is a very tricky code that setup a mapping of effective skill
    // level and an array of skill names (>0).
    _skill = ([]);
    sname = filter_array(keys(skl) + keys(lrn), (: undefinedp($3[$1]) ? $3[$1] = $2->query_skill($1) : 0 :), ob, _skill );

    map = ob->query_skill_map();

    if( mapp(map) ) mapped = values(map);
    else mapped = ({});

    sname = sort_array( keys(_skill), (: sk_sort :) );
//    sname = sort_array( keys(_skill) , (: _skill[$2] - _skill[$1] :));

    line += "�u�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�t\n";
    foreach(s in sname ) {
    line += sprintf("�x%s%s %-37s %s %3s %-6s%7s�x\n",
                        skill_class(s),
                        skill_ability(ability[s]),
                        to_chinese(s) + "(" + s + ")",
                        skill_level(SKILL_D(s)->type(), skl[s]),
                        ob->skill_mapped(s) ?  ""+_skill[s] : HIK"---"NOR,
                        ( ob->skill_mapped(s) && _skill[s] != skl[s]) ? (sprintf("(%+d)", _skill[s] - skl[s])) : "",
                        (( flag[s] & SKILL_FLAG_ABANDONED ) ? HIK" ------"NOR : 
                            ( !require[s] ? "00.00%" : sprintf("%2.2f",lrn[s]*100.0/require[s]) +"%" )) );
                
    }
    line += "���w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��";
    this_player()->start_more(line);
    return 1;
}

string skill_level(string type, int level)
{
    int grade;

      grade = level/10;

    switch(type) {
        case "knowledge":
            if( grade >= sizeof(knowledge_level_desc) )
                grade = sizeof(knowledge_level_desc)-1;
            return knowledge_level_desc[grade];
        default:
            if( grade >= sizeof(skill_level_desc) )
                grade = sizeof(skill_level_desc)-1;
            return skill_level_desc[grade];
    }
}

int help(object me)
{
    write(@HELP
���O�榡 : skills [<�Y�H>]

�o�ӫ��O�i�H���A�d�߾ǹL���ޯ�θg��ȡA��i�d���M�A���v�{���Y����H����
�બ�p�C

�Ův�i�H�d�ߥ���H�� NPC ���ޯબ�p�C

disable ���ޯ�b�ޯ൥�Ū������H --- ���
abandon ���ޯ�b�ޯ�g�窺�����H --- ���

�p�G�A���ޯ�]�� disable �άO abandon �n�٭�ɵo�Ͱ��D
�A�i�H�յۥΫ��O skills -clear �ӲM�� disable �� abandon ���аO
�o�ӫ��O���|�v�T�A���ޯ൥�ũάO�g��A�u�O�M���аO��

�������O�Genable�Bdisable�Babandon
HELP
    );
    return 1;
}

