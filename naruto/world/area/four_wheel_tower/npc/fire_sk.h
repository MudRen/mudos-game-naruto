int isSock(object ob, object enemy)
{
    return (COMBAT_D->sock(ob, enemy, 1) > random(100));
}

void do_fight()
{
    int damage, raiseDamage, x, y, lv, sock, exact, evade;
    object enemy, item;
    object* targets;
    mapping cnd = ([]);

    // �S���ĤH
    enemy = this_object()->query_opponent();
    targets = this_object()->query_enemy();

    if( !enemy ) return;
    // �ĤH�b���P��m
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    lv = query_level();

    switch( random(lv-30) ) {
        case 0..5:
            x = this_object()->query("area_info/x_axis");
            y = this_object()->query("area_info/y_axis");
            exact = COMBAT_D->intimidate(this_object(), 1)*1.2;
            evade = COMBAT_D->wittiness(enemy, 1);

            if( !environment(this_object())->is_area() || !environment(this_object())->query_data(x, y, "terrainDamage") ) return;
            message_vision(HIR"\n$N���۶ø��a����������A���⾮�E�_�ӡA�C�C�X�{�@��"HIY"���y"HIR"...\n"NOR, this_object());
            if( COMBAT_D->SkillHit(this_object(), enemy, exact, evade) ) {
                raiseDamage = lv*7;

                add_temp("apply/attack", raiseDamage); 
                damage = COMBAT_D->isDamage(this_object(), enemy, 0);
                add_temp("apply/attack", -raiseDamage);

                if( damage < lv*2 ) damage = lv + random(lv);

                // �ˮ`�ާl��
                damage = COMBAT_D->receive_damage(enemy, this_object(), damage);
                enemy->receive_damage(damage, this_object());
                message_vision( sprintf("$N���@�i�u"HIY"�t����\\"NOR"�v�F���@�n�N$n�����X�h(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
            } else {
                message_vision("���O���y���~���t�A�ܧ֦a�N�����F�C\n\n"NOR, this_object());
            }
            return;
            break;
        case 6..15:
            if( query_condition("body_strength_cond") ) return;

            message_vision(HIW"\n$N�ؤ�������n�ۤ�G�A�����v�����ɡA���ηU�ӷU���j�I\n"NOR, this_object());
            message_vision(HIR"$N�ɧq�@�n�A���G�w�g���Ƨ����F�C\n\n"NOR, this_object());

            cnd["name"] = HIR"���j��"NOR;
            cnd["duration"] = lv*10;
            cnd["attack"] = lv*2;
            cnd["armor"] = lv;

            set_condition("body_strength_cond", cnd);
            start_busy(2);
            return;
            break;
        case 16..25:
            set_skill("sock power", lv*2);
            sock = isSock(this_object(), enemy);
            exact = COMBAT_D->intimidate(this_object(), 1);
            evade = COMBAT_D->wittiness(enemy, 1);
            delete_skill("sock power");

            if( sock ) message_vision(HIR"\n(�P�R�@��) "HIY"$N�k�u�@�}�z���u"HIW"�j�O�w�U��"HIY"�v$N���⼵�a�ĦV�e��A�����ֳt�{�V$n�I\n"NOR, this_object(), enemy);
            else message_vision(HIY"\n$N�ϰʥk�u�u"HIW"�w�U��"HIY"�v$N�ǥs�@�n�A�N�O�q������k�u�j�O�@���I\n"NOR, this_object());

            if( COMBAT_D->SkillHit(this_object(), enemy, exact, evade) ) {
                raiseDamage = lv*6;

                add_temp("apply/attack", raiseDamage);
                damage = COMBAT_D->isDamage(this_object(), enemy, 0);
                add_temp("apply/attack", -raiseDamage);

                if( damage < lv*2 ) damage = lv + random(lv);
                if( sock ) damage = (damage * COMBAT_D->sockPower(this_object(), enemy, 1))/100;

                enemy->receive_damage(damage, this_object());
                message_vision( sprintf("�u�I�v�a�@�n�A$n�u�Pı���U�@�}�@�h��@�L��ı�A�n���Q���_�F(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
            } else {
                message_vision("���G���Y�����F�A�b$n�Y�ǧj�_�@�}�j���A�~��$n�@���N���C\n\n"NOR, this_object(), enemy);
                start_busy(4);
            }
            return;
            break;
        case 26..35:
            exact = COMBAT_D->intimidate(this_object(), 1)*9/10;
            evade = COMBAT_D->wittiness(enemy, 1);

            message_vision(HIR"\n$N�F���a�Ĩ�$n"HIR"���e�A�@���u"HIW"�w�U��"NOR"�E"HIY"���x�v��"HIR"�v�W������@������I\n"NOR, this_object(), enemy);
            for(x=0;x<4;x++) {
                if( COMBAT_D->SkillHit(this_object(), enemy, exact, evade) ) {
                    raiseDamage = lv*5;

                    add_temp("apply/attack", raiseDamage); 
                    damage = COMBAT_D->isDamage(this_object(), enemy, 0);
                    add_temp("apply/attack", -raiseDamage);

                    if( damage < lv*2 ) damage = lv + random(lv);

                    enemy->receive_damage(damage, this_object());
                    message_vision( sprintf("$n����o�O���������A���l�k�h���w�A�z�z�j�s(%d) %s\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
                } else {
                    message_vision("�٦n$N�\�ҽm������a�A�o�O�����èS�����\�C\n"NOR, this_object(), enemy);
                }
            }
            start_busy(3);
            message_vision("\n"NOR, this_object());
            return;
            break;
    }
}