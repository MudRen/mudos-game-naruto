void do_fight()
{
    int damage, raiseDamage, i, exact, evade;
    object enemy, me;
    mapping cnd = ([]);

    // �S���ĤH
    me = this_object();
    enemy = me->query_opponent();
    if( !enemy ) return;

    // �ĤH�b���P��m
    if( environment(me)->is_area() ) {
        if( !area_environment(me, enemy) ) return;
    } else {
        if( environment(enemy) != environment(me) ) return;
    }
    switch( me->query("sktree") ) {
        case 1: // ���A�p��
            exact = COMBAT_D->exact(me, enemy, 1) + COMBAT_D->intimidate(me, 1);
            evade = COMBAT_D->evade(enemy, me, 1) + COMBAT_D->intimidate(enemy, 1);

            message_vision("\n$N�q�I�᮳�X������M�����a�b��W�A�ˡA���M�@��½����$n�Y�F�L�ӡI\n", me, enemy);
            if( !COMBAT_D->SkillHit(me, enemy, exact, evade) ) {
                message_vision(HIC"���G���M�������g�ŤF�A�o����$N��ɤS���X������M�⪱�ۡC\n\n"NOR, me, enemy);
                me->damage_stat("mp", 20, me);
                me->start_busy(2);
                return;
            }
            i = random(5) + 1;
            raiseDamage = 150*i;

            me->add_temp("apply/attack", raiseDamage); 
            damage = COMBAT_D->isDamage(me, enemy, this_object());
            me->add_temp("apply/attack", -raiseDamage);

            if( damage < 100 ) damage = 10 + random(90);

            // �ˮ`�ާl��
            damage = COMBAT_D->receive_damage(enemy, me, damage);
            enemy->receive_damage(damage, me);
            message_vision( sprintf(HIC"�u�����v���n�u��"+chinese_number(i)+"����M�������ʦa���b$n�����W�A��y�p�W"NOR"(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), me, enemy);
            me->damage_stat("mp", 20, me);
            me->start_busy(1);
            break;

        case 2: // �]�N�p��
            exact = COMBAT_D->exact(me, enemy, 1)/3;
            add_temp("apply/exact", exact);

            message_vision("\n$N���X�@���¥��A�N��W���P���]�F�_�ӡA�y�W�S�X�޲������e...\n"NOR, me, enemy);
            if( !COMBAT_D->isHit(me, enemy) ) {
                message_vision(HIM"����$N�q�¥������X�@���p�ըߵM��j�n���D�G����$n���[��I\n\n"NOR, me, enemy);
                me->damage_stat("mp", 10, me);
                me->start_busy(1);
                return;
            }
            raiseDamage = 300 + random(300);

            me->add_temp("apply/attack", raiseDamage); 
            damage = COMBAT_D->isDamage(me, enemy, this_object());
            me->add_temp("apply/attack", -raiseDamage);

            if( damage < 200 ) damage = 120 + random(80);

            enemy->receive_damage(damage, me);
            me->damage_stat("mp", 20, me);
            message_vision( sprintf(HIM"���M�b$n�����̪ťX�{�@�����ۤP������A�ΤO��F$n�@�M"NOR"(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), me, enemy);
            add_temp("apply/exact", -exact);
            me->start_busy(1);
            break;

        case 3: // �Ť����H
            exact = COMBAT_D->exact(me, enemy, 1)/4;
            add_temp("apply/exact", exact);

            message_vision("\n$N���M�@���ƤV�I���Ť������H���֦a��$n���F�L�h�I\n", me, enemy);
            if( !COMBAT_D->isHit(me, enemy) ) {
                message_vision(HIW"���G$n�o�{�F$N�����ʤ�V�A$N�u�n�������S���F�U�ӡC\n\n"NOR, me, enemy);
                me->damage_stat("mp", 20, me);
                me->start_busy(1);
                return;
            }
            raiseDamage = 400 + random(200);

            me->add_temp("apply/attack", raiseDamage); 
            damage = COMBAT_D->isDamage(me, enemy, this_object());
            me->add_temp("apply/attack", -raiseDamage);

            if( damage < 150 ) damage = 100 + random(50);

            enemy->receive_damage(damage, me);
            me->damage_stat("mp", 20, me);
            message_vision( sprintf(HIW"�u��$N�H���}�Ħ����H���F$n�@�O�������W�Į�"NOR"(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), me, enemy);
            add_temp("apply/exact", -exact);
            me->start_busy(1);
            break;

        case 4: // ��y�p��
            exact = COMBAT_D->exact(me, enemy, 1)*1.6;
            evade = COMBAT_D->evade(enemy, me, 1)*1.5;

            message_vision("\n$N�N��b�}�U���j�y�ΤO�@½�A�����y�ֳt���g�V$n�C\n", me, enemy);
            if( !COMBAT_D->SkillHit(me, enemy, exact, evade) ) {
                message_vision(HIG"$n�y�L���k�@�h�׶}�F�����A�������$N�S��y��^�}�U�C\n\n"NOR, me, enemy);

                me->damage_stat("mp", 20, me);
                me->start_busy(2);
                return;
            }
            raiseDamage = 500 + random(100);

            me->add_temp("apply/attack", raiseDamage); 
            damage = COMBAT_D->isDamage(me, enemy, this_object());
            me->add_temp("apply/attack", -raiseDamage);

            if( damage < 150 ) damage = 80 + random(70);

            // �ˮ`�ާl��
            damage = COMBAT_D->receive_damage(enemy, me, damage);
            enemy->receive_damage(damage, me);
            message_vision( sprintf(HIG"�u�S�v�a�@�n�A$n�N���Q�K�y�����A��ӤH�s�z����"NOR"(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), me, enemy);
            me->damage_stat("mp", 20, me);
            me->start_busy(1);
            break;

        case 5: // ����p��
            exact = COMBAT_D->intimidate(me, 1);
            evade = COMBAT_D->wittiness(enemy, 1);

            message_vision("\n$N���_���b�U�N�����黡�D�G"HIG"��$n�ԡI�ֱq�o�����L�h�I\n"NOR, me, enemy);
            if( !COMBAT_D->SkillHit(me, enemy, exact, evade) ) {
                message_vision(HIR"$N�N�����$n��F�L�ӡA���O$n�����B�����q���餤�߸��F�L�h�C\n\n"NOR, me, enemy);
                me->damage_stat("mp", 20, me);
                me->start_busy(2);
                return;
            }
            raiseDamage = 200;

            me->add_temp("apply/attack", raiseDamage); 
            damage = COMBAT_D->isDamage(me, enemy, this_object());
            me->add_temp("apply/attack", -raiseDamage);

            if( damage < 50 ) damage = 20 + random(30);

            enemy->receive_damage(damage, me);
            message_vision( sprintf(HIR"���O$N�S�g�L�V�m�����L����A�����Q���K�N�ˤF"NOR"(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), me, enemy);
            me->damage_stat("mp", 30, me);
            me->start_busy(1);

            cnd["name"] = HIR+"�N��"+NOR;
            cnd["duration"] = 5;
            cnd["from"] = me;

            enemy->set_condition("firedamage", cnd);
            break;
    }
}