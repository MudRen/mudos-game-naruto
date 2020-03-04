/* consider.c */

inherit F_CLEAN_UP;

string consider(int ability)
{
	if( ability < -150 ) return "���ө�A";
	if( ability < -80 ) return "���X�A�Ʀh";
	if( ability < -40 ) return "���X�A�@�I";
	if( ability < -10 ) return "��A���Ӥ@�w";
	if( ability < 10 ) return "�P�A�u�b�B�򤧶�";
	if( ability < 40 ) return "�����A�@�w";
	if( ability < 80 ) return "�M�A�ۤ�ۮt�@�I";
	if( ability < 150 ) return "�M�A�ۤ�ᬰ���p";
	return "������A";
}

int main(object me, string arg)
{
    object ob, weapon;
	int me_ability, ob_ability;
    mapping wielded_weapon;
    string msg, sk, art, skill;

	if( !arg ) return notify_fail("�A�Q�����֪���O�H\n");
	
	ob = present(arg, environment(me));
	if( !ob || !ob->is_character() || !ob->visible(me) )
	    return notify_fail("�o�̨S�� " + arg + " �o�ӤH�C\n");

    msg = "�A����" + ob->query("name") + "����O�G\n";
    
    // �����O�q
    me_ability = 0;
    wielded_weapon = me->query_temp("weapon");
    if( mapp(wielded_weapon) && sizeof(wielded_weapon) ) {
        foreach(skill, weapon in wielded_weapon) {
            art = me->skill_mapped("combat");
            if( ! art ) continue;
            me_ability += weapon->show_damage();
        }
    } else me_ability = me->show_damage();

    ob_ability = 0;
    wielded_weapon = ob->query_temp("weapon");
    if( mapp(wielded_weapon) && sizeof(wielded_weapon) ) {
        foreach(skill, weapon in wielded_weapon) {
            art = ob->skill_mapped("combat");
            if( ! art ) continue;
            ob_ability += weapon->show_damage();
        }
    } else ob_ability = ob->show_damage();

    msg += "�����O�q" + consider(me_ability-ob_ability);

    // ���m�O
    me_ability = me->query_ability("defend");
    if( (sk=me->skill_mapped("parry")) ) me_ability += SKILL_D(sk)->parry_show(me, 0);

    ob_ability = ob->query_ability("defend");
    if( (sk=ob->skill_mapped("parry")) ) ob_ability += SKILL_D(sk)->parry_show(ob, 0);

    msg += "�A���m�O�q" + consider(me_ability-ob_ability) + "�C\n";

    // �����ޥ�
    me_ability = me->query_ability("intimidate"),
    ob_ability = ob->query_ability("intimidate"),

    msg += "�����ޥ�" + consider(me_ability-ob_ability);

    // ���m�ޥ�
    me_ability = me->query_ability("wittiness"),
    ob_ability = ob->query_ability("wittiness"),

    msg += "�A���m�ޥ�" + consider(me_ability-ob_ability) + "�C\n";

    // �R���v
    me_ability = me->exact();
    ob_ability = ob->exact();

    msg += "�R����O" + consider(me_ability-ob_ability);

    // �j�ײv
    me_ability = me->query_ability("evade");
    if( (sk=me->skill_mapped("dodge")) ) me_ability += SKILL_D(sk)->dodge_show(me, 0);

    ob_ability = ob->query_ability("evade");
    if( (sk=ob->skill_mapped("dodge")) ) ob_ability += SKILL_D(sk)->dodge_show(ob, 0);

    msg += "�A�j�ׯ�O" + consider(me_ability-ob_ability) + "�C\n";

    write(msg);

    return 1;
}

int help()
{
    write(@TEXT
���O�榡�Gconsider ��H

�o�ӫ��O���A�j�������@�ӹ�⪺��O�C
TEXT);
    return 1;
}
