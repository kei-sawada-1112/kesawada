#include <stdlib.h>
#include <stdio.h>

int ft_strcmp(char *str1, char *str2)
{
    while (*str1 && *str2 && (*str1 == *str2))
    {
        if (*str1 == *str2)
        {
            str1++;
            str2++;
        }
    }
    return (*str1 - *str2);
}

typedef struct s_hashentry {
    char *key;
    char *value;
    struct s_hashentry* next;
} t_hashentry;

typedef struct {
    t_hashentry** table;
    int size;
} t_hashtable;

t_hashtable* hash_create(int size);
void hash_insert(t_hashtable* hash, char *key, char *value);
char* hash_search(t_hashtable* hash, char *key);
void hash_delete(t_hashtable* hash, char *key);

t_hashtable *hash_create(int size)
{
    t_hashtable *hash_table = (t_hashtable *)malloc(sizeof(t_hashtable));
    if (!hash_table)
        return NULL;

    hash_table->table = (t_hashentry **)malloc(sizeof(t_hashentry *) * size);
    if (!hash_table->table)
    {
        free(hash_table);
        return NULL;
    }

    for (int i = 0; i < size; i++)
        hash_table->table[i] = NULL;
    hash_table->size = size;

    return hash_table;
}

unsigned int hash_function(char *key, int table_size)
{
    unsigned int hash = 0;
    while (*key)
    {
        hash = (hash << 5) + *key;
        key++;
    }
    return hash % table_size;
}

char *hash_search(t_hashtable* hash, char *key)
{
    if (!hash || !key)
        return NULL;

    int i = 0;
    unsigned int index = hash_function(key, hash->size);
    t_hashentry *entry = hash->table[index];
    while (entry)
    {
        if (ft_strcmp(entry->key, key) == 0)
            return entry->value;
        entry = entry->next;
    }
    return NULL;
}

void hash_insert(t_hashtable* hash, char *key, char *value)
{
    unsigned int hash_value = hash_function(key, hash->size);
    t_hashentry *new_entry = (t_hashentry *)malloc(sizeof(t_hashentry));
    if (!new_entry)
        return ;
    
    new_entry->key = key;
    new_entry->value = value;
    new_entry->next = hash->table[hash_value];
    hash->table[hash_value] = new_entry;
}

void hash_delete(t_hashtable* hash, char *key)
{
    unsigned int hash_value = hash_function(key, hash->size);

    t_hashentry *entry = hash->table[hash_value];
    t_hashentry *prev_entry = NULL;

    while (entry)
    {
        if (ft_strcmp(entry->key, key) == 0)
        {
            if (prev_entry)
            {
                prev_entry->next = entry->next;
            }
            else {
                hash->table[hash_value] = entry->next;
            }
            free(entry);
            return ;
        }
        prev_entry = entry;
        entry = entry->next;
    }
}

int main(void) {
    // ハッシュテーブルの作成（例としてサイズを10とする）
    t_hashtable *hash = hash_create(10);

    // キーと値を挿入
    hash_insert(hash, "apple", "fruit");
    hash_insert(hash, "carrot", "vegetable");
    hash_insert(hash, "chicken", "meat");

    // 値を検索
    printf("apple: %s\n", hash_search(hash, "apple"));
    printf("carrot: %s\n", hash_search(hash, "carrot"));
    printf("chicken: %s\n", hash_search(hash, "chicken"));

    // 値を削除
    hash_delete(hash, "carrot");
    printf("carrot (after deletion): %s\n", hash_search(hash, "carrot"));

    return 0;
}