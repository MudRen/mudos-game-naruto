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
            exact = COMBAT_D->wittiness(this_object(), 1)*1.2;
            evade = COMBAT_D->intimidate(enemy, 1);

            if( enemy->query_condition("bad_mud") ) return;
            if( !environment(this_object())->is_area() || !environment(this_object())->query_data(x, y, "terrainDamage") ) return;
            message_vision(YEL"\n$N���X�H�H������A�����a�b�F�а襤�ͨ��ͥh�ͨ��ͥh...\n"NOR, this_object());
            if( COMBAT_D->SkillHit(this_object(), enemy, exact, evade) ) {
                message_vision("$N�N�F�д|���y���{�b$n���W�I$n�����O�d��ê�F�����I\n\n"NOR, this_object(), enemy);

                cnd["name"] = BYEL"��d��"NOR;
                cnd["duration"] = lv*10;
                cnd["attack"] = enemy->query("level")*5;
                cnd["intimidate"] = enemy->query("level");

                enemy->set_condition("bad_mud", cnd);
            } else {
                message_vision("$N�̩I�I�a�Τ�k�Y�A�˪����Y���O�F�СC\n\n"NOR, this_object());
            }
            return;
            break;
        case 6..15:
            exact = COMBAT_D->wittiness(this_object(), 1);
            evade = COMBAT_D->intimidate(enemy, 1);

            message_vision(HIK"\n$N���X�@�ΥR���u�ʪ�"HIY"�u�����d�v"HIK"�ǥs�@�n�N��$n��F�L�h�I\n"NOR, this_object(), enemy);
            if( COMBAT_D->SkillHit(this_object(), enemy, exact, evade) ) {
                raiseDamage = lv*6;

                add_temp("apply/attack", raiseDamage);
                damage = COMBAT_D->isDamage(this_object(), enemy, 0);
                add_temp("apply/attack", -raiseDamage);

                if( damage < lv ) damage = lv/2 + random(lv)/2;
                enemy->receive_damage(damage, this_object());

                // �ˮ`�ާl��
                damage = COMBAT_D->receive_damage(enemy, this_object(), damage);
                message_vision( sprintf("��d����$n��o�X���ߪ�����A��$n�s�Q�Ѫ����\���R�X�ӤF(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
            } else {
                message_vision("�٦n$N�{�����֡A��d�{�b�a�W�A�o�X���p�j�K�몺���...\n\n"NOR, enemy);
                start_busy(2);
            }
            return;
            break;
        case 16..25:
            if( query_condition("body_strength_cond") ) return;
            message_vision(HIY"\n$N������@�Y�@�ȡA���M�����o�X���ݯ몺���A"NOR+YEL"�u�w�ơv\n"NOR, this_object());
            message_vision(HIW"�@�}ģ�������~��A$N���l���G�ܵw�F�I\n\n"NOR, this_object());

            cnd["name"] = HIY"�w��"NOR;
            cnd["duration"] = lv*10;
            cnd["attack"] = 0;
            cnd["armor"] = lv*5;

            set_condition("body_strength_cond", cnd);
            start_busy(2);
            return;
            break;
        case 26..35:
            exact = COMBAT_D->wittiness(this_object(), 1);
            evade = COMBAT_D->intimidate(enemy, 1);

            message_vision(HIK"\n$N�i�}�j�L�A��$n�R�X�@�κ����"NOR+GRN"�u�v�ܬr�v"HIK"���ۤS�R�X"HIR"���K"HIK"�I\n"NOR, this_object(), enemy);
            if( COMBAT_D->SkillHit(this_object(), enemy, exact, evade) ) {

                raiseDamage = lv*3;

                add_temp("apply/attack", raiseDamage);
                damage = COMBAT_D->isDamage(this_object(), enemy, 0);
                add_temp("apply/attack", -raiseDamage);

                if( damage < lv ) damage = lv/2 + random(lv)/2;
                enemy->receive_damage(damage, this_object());

                message_vision( sprintf("$n�{�פ���Q�u�v�ܬr�v�����A����K�Q�ܮɵo�ͤ@�}�@�P�z��(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);

                cnd["name"] = GRN"�v�ܬr"NOR;
                cnd["duration"] = lv/2;
                cnd["from"] = this_object();

                if( !enemy->query_condition("vp") ) {
                    tell_object(enemy, HIG"(�v�ܬr�I�J�F�A���餺�A�ϧA�h�W�����C)\n"NOR);
                    enemy->set_condition("vp", cnd);
                }
                cnd["name"] = HIR"�r�z"NOR;
                cnd["duration"] = lv/5;
                cnd["from"] = this_object();

                if( !enemy->query_condition("firedamage") ) {
                    tell_object(enemy, HIR"(�]���r�z�ϧA�N�ˤF�I)\n"NOR);
                    enemy->set_condition("firedamage", cnd);
                }
            } else {
                message_vision("�{�b�a�W��"GRN"�u�v�ܬr�v"NOR"�Q���K�Q���A�o�X�@�s�ꪺ�p�z���C\n\n"NOR, this_object());
            }
            return;
            break;
    }
}