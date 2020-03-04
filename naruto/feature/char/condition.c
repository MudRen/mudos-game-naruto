/* condition.c ���Ī��A
   create by Acme 20070329
*/

#include <condition.h>

mapping conditions = ([]);

// �q�ɮר��^���Ī��A��ƫ�A��_���Ī��A���v�T�C
void restore_condition()
{
    string cnd;
    mixed cnd_data;

    if( !mapp(conditions) || !sizeof(conditions) )
        return;

    foreach(cnd, cnd_data in conditions)
        CONDITION_D(cnd)->condition_apply(this_object(), cnd, cnd_data);
}

// �C���߸���s���Ī��A
void update_condition()
{
    string cnd;
    mapping cnd_data;

    if( !mapp(conditions) || !sizeof(conditions) ) return;

    foreach(cnd, cnd_data in conditions)
        CONDITION_D(cnd)->condition_update(this_object(), cnd, cnd_data);
}

// �R�����Ī��A
void delete_condition(string cnd)
{
    if( !mapp(conditions) || !sizeof(conditions) ) return;
    if( undefinedp(conditions[cnd]) ) return;

    
    CONDITION_D(cnd)->condition_unapply(this_object(), cnd, conditions[cnd]);
    map_delete(conditions, cnd);
}

// �M���Ҧ����Ī��A
void clear_condition()
{
    string cnd;
    mapping cnd_data;

    if( !mapp(conditions) || !sizeof(conditions) ) return;

    foreach(cnd, cnd_data in conditions) {
        if( cnd_data["no_clear"] ) continue;  // �p�G������R�����\��N�����R
        delete_condition(cnd);
    }
}

// �]�w���Ī��A
void set_condition(string cnd, mapping info)
{
    string key, *buff;

    if( !info || !mapp(info) ) return;
    if( !mapp(conditions) ) conditions = ([]);
    
    // �w�g�s�b�o�� condition, �h������
    if( !undefinedp(conditions[cnd]) )
        delete_condition(cnd);

    buff = keys(info);
    conditions[cnd] = ([]);

    foreach(key in buff)
        conditions[cnd][key] = info[key];

    CONDITION_D(cnd)->condition_apply(this_object(), cnd, conditions[cnd]);
}

mapping query_condition(string cnd)
{
    if( !mapp(conditions) || !sizeof(conditions) ) return 0;
    if( undefinedp(conditions[cnd]) ) return 0;
    return conditions[cnd];
}

mapping query_all_conditions()
{
    return conditions;
}
