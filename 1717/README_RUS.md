1717. Максимальный результат удаления подстрок
Середина
Темы
значок премиум-замка
Компании
Намекать
Вам дана строка sи два целых числа xи y. Вы можете выполнить два типа операций любое количество раз.

Удалить подстроку "ab"и получить xочки.
Например, при удалении "ab"из него становится ."cabxbae""cxbae"
Удалить подстроку "ba"и получить yочки.
Например, при удалении "ba"из него становится ."cabxbae""cabxe"
Верните максимальное количество очков, которое вы можете получить после применения вышеуказанных операций s .

 

Пример 1:

Ввод: s = "cdbcbbaaabab", x = 4, y = 5.
 Вывод: 19.
 Пояснение: 
— Удалите подчёркнутое "ba" из "cdbcbbaaa ba b". Теперь s = "cdbcbbaaab", и к результату добавляется 5 очков.
- Уберите подчёркнутое «ab» из «cdbcbbaa ab ». Теперь s = «cdbcbbaa», и к счёту добавляется 4 очка.
- Уберите подчёркнутое «ba» из «cdbcb ba a». Теперь s = «cdbcba», и к счёту добавляется 5 очков.
- Уберите подчёркнутое «ba» в «cdbc ba ». Теперь s = «cdbc», и к счёту добавляется 5 очков.
Общая оценка = 5 + 4 + 5 + 5 = 19.
Пример 2:

Вход: s = "aabbaaxybbaabb", x = 5, y = 4
 Выход: 20
 

Ограничения:

1 <= s.length <= 105
1 <= x, y <= 104
sсостоит из строчных английских букв.