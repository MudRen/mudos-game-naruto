/* bank.c write by -Acme */
#include <ansi.h>

inherit ROOM;

void init()
{
    add_action("do_withdraw", "withdraw");
    add_action("do_deposit", "deposit");
    add_action("do_outward", "outward");
}

int do_withdraw(string arg)
{
    int amount, value;
    string money;
    object money_ob, bond;

    seteuid(getuid());

    if( !arg || sscanf(arg, "%d %s", amount, money) != 2 )
        return notify_fail("���O�榡�Rwithdraw <�ƶq> <�f������>�C\n");

    if( amount < 0 )
        return notify_fail("�A���ണ��s�H�U���f���C\n");

    if( amount > 30000) 
        return notify_fail("�A����@����Ӧh�C\n");    

    if( file_size("obj/money/" + money + ".c") < 0 )
    return notify_fail("�A�n������@�ؿ��S\n");

    if( catch(money_ob = new("/obj/money/" + money)) ) return 0;

    money_ob->set_amount(amount);
    value = money_ob->value();
    if( this_player()->query("bank") < value ) {
        destruct(money_ob);
        return notify_fail("�A�����Y�̨S���o��h���C\n");
    }

    if( !money_ob->move(this_player()) ) {
        destruct(money_ob);
        return notify_fail("�A���W�a���F�o�\\�h���M���֤@�I�a�C\n");
    }

    // �q�b�ᦩ��
    this_player()->add("bank", -value);

    write("�A�q�Ȧ洣�X" + chinese_number(amount) + money_ob->query("unit") + money_ob->name() + "�C\n");

    return 1;
}

int do_deposit(string arg)
{
    int amount;
    string money;
    object money_ob;

    seteuid(getuid());

    if( !arg || sscanf(arg, "%d %s", amount, money) != 2 )
        return notify_fail("���O�榡�Rdeposit <�ƶq> <�f������>�C\n");

    if( amount < 0 )
        return notify_fail("�A����s�J�s�H�U�������C\n");
        
    if( !money_ob = present(money + "_money", this_player()) )
        return notify_fail("�A���W�S���o�ؿ����C\n");

    if( money_ob->query_amount() < amount )
        return notify_fail("�A���W�S���o��h��" + money_ob->name() + "�C\n");

    write("�A�N" + chinese_number(amount) + money_ob->query("unit") + money_ob->name() + "�s�J�Ȧ�C\n");

    // �[�b�Ȧ��
    this_player()->add("bank", money_ob->query("base_value") * amount);

    // ���W�����ƶq���
    money_ob->add_amount( -amount );

    if( money_ob->query_amount() <= 0 ) destruct(money_ob);

    this_player()->save_autoload();
    this_player()->save();

    return 1;
}

int do_outward(string arg)
{
    int amount;
    string id;
    object target;

    if( !arg || sscanf(arg, "%s %d", id, amount) != 2 )
        return notify_fail("���O�榡�G outward <�H��> <�ƶq>\n");

    if( amount <= 0 ) return notify_fail("�A����ץX�p��s�H�U���ƶq�C\n");
    if( amount > 1000000 ) return notify_fail("�A�@������ץX�W�L�@�ʸU�Ȩ�C\n");

    if( amount > this_player()->query("bank") ) 
    return notify_fail("�A�Ȧ�̨S���o��h�����C\n");

    target = find_player(id);
    if( !target ) return notify_fail("�u�W�S���o�ӤH....�C\n");

    if( target == this_player() ) return notify_fail("�A�n�׵��ۤw�H\n");

    // ����
    this_player()->add("bank", -amount);

    // �ץX�T���A����O
    tell_object(this_player(), "�A�N " + amount + " ��Ȥl�׵��F" + target->name() + "�C\n");
    if( amount >= 10 ) tell_object(target, HIY"(�Ȧ�V�⨫�F" + this_player()->name() + "�רӪ��� 10% ����O�ΡC)\n"NOR);

    amount = amount - (amount/10);

    // �פJ�T��
    tell_object(target, HIW+this_player()->name()+"�N " + amount + " ��Ȥl�פJ��A���b����Y�C\n"NOR);

    // �[��
    target->add("bank", amount);

    log_file( "static/OUTWARD", sprintf("[%s] %s outward %d to %s\n",
       ctime(time()), geteuid(this_player()), amount, geteuid(target)) );
    return 1;
}
