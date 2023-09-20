# OOP2-Clash-Royale

כותרת:
===========================================================
פרוייקט סיום: Clash Royale


פרטי הסטודנטיות:
===========================================================
רוני כהן, רעות מיכאלי


הסבר כללי של הפרוייקט:
===========================================================
בפרוייקט זה מימשנו את המשחק Clash Royale.
זהו משחק אסטרטגי שבו מטרת השחקן היא להצליח להרוס את מגדליו של המחשב תוך שימוש בקלפים שונים,
והתמודדות והתגוננות מול המחשב, שגם הוא מכוון להריסת מגדליו של השחקן תוך שימוש בקלפים.


תיכון:
===========================================================
קיימות שתי מחלקות עיקריות שאחראיות על תפקוד התפריט הראשי ומסך המשחק עצמו. שתיהן מנוהלות במחלקת החלון.
קיימת מחלקה לכל דף בתפריט.
ישנה מחלקה ראשית לקלפים במשחק, ומחלקה בנפרד לכל קלף.
במשחק קיימים אובייקטים שזזים ואובייקטים שאינם זזים, לשני הסוגים מחלקה משלהם, ולשתי המחלקות האלו יש מחלקה כללית של אובייקטים.
לכל אובייקט שזז ולכל אובייקט שאינו זז יש מחלקה משלו.
קיימת מחלקה שמנהלת את ההתנגשויות בין כל האובייקטים במשחק, וקיימת מחלקת סינגלטון.




רשימת קבצים עם הסבר:
=========================================================================
קבצי header:

1. Window.h - מחלקה זו אחראית על החלון המציג את המשחק.
2. Controller.h - מחלקה זו אחראית על הצגת התפריט הראשי המכיל 3 מסכים שונים: הוראות משחק, אוסף הקלפים, והמסך הראשי.
3. ArenaBattle.h - מחלקה זו אחראית על התנהלותו של שלב במשחק. היא מתחילה לנהל את המשחק עצמו ברגע שהשחקן לוחץ על הכפתור 
		"battle" במסך הראשי בתפריט. 
4. View.h - זוהי מחלקת הבסיס לעמודים השונים בתפריט.
5. Archers.h - מחלקה זו מייצגת קלף במשחק מסוג archers. מכילה פרטים על הקלף. זהו קלף מסוג troop.
6. ArchersObj.h - מחלקה זו מייצגת את האובייקט archers. זהו אובייקט זז של המשחק. המחלקה מכילה פונקציות יצירה, תזוזה, ואנימציה של האובייקט.
		ובדומה, כל מחלקה שמייצגת אובייקט שזז במשחק מכילה את אותן הפונקציות, כאשר בכל מחלקה המימוש שונה בהתאם לאובייקט.
7. Arrows.h - מחלקה זו מייצגת קלף במשחק מסוג arrows. זהו קלף מסוג spell.
8. ArrowsObj.h - מחלקה זו מייצגת את האובייקט arrows. זהו אובייקט זז של המשחק.
9. BattleEndScreen.h - זוהי מחלקה המייצגת את מסך הסיום של שלב במשחק - אחראית על תצוגת מסך נצחון / הפסד.
10. BattlePage.h - זוהי מחלקה המייצגת את המסך הראשי בתפריט המשחק. זהו המסך הראשון שרואים כאשר מריצים את המשחק.
11. Bullet.h - מחלקה זו מייצגת את האובייקט bullet. זהו אובייקט זז של המשחק.
12. Card.h - זוהי מחלקת הבסיס של הקלפים במשחק. מכילה פונקציות ותכונות משותפות לכל הקלפים במשחק.
13. CardsPage.h - אחראית על מסך אוסף הקלפים בתפריט. זהו המסך המוצג בלחיצה על לשונית "Collection".
14. CollisionHandling.h - זוהי המחלקה שאחראית על כל ההתנגשויות האפשריות במשחק בין כל סוגי האובייקטים.
15. DartGoblin.h - מחלקה זו מייצגת קלף במשחק מסוג dart goblin. זהו קלף מסוג troop.
16. DartGoblinObj.h - מחלקה זו מייצגת את האובייקט dart goblin. זהו אובייקט זז של המשחק.
17. Factory.h - זוהי מחלקת Factory, שאחראית על ייצור כל סוגי האובייקטים של המשחק.
18. Fireball.h - מחלקה זו מייצגת קלף במשחק מסוג fireball. זהו קלף מסוג spell.
19. FireballObj.h - מחלקה זו מייצגת את האובייקט fireball. זהו אובייקט זז של המשחק.
20. Freeze.h - מחלקה זו מייצגת קלף במשחק מסוג freeze. זהו קלף מסוג spell.
21. FreezeObj.h - מחלקה זו מייצגת את האובייקט freeze. זהו אובייקט זז של המשחק.
22. Giant.h - מחלקה זו מייצגת קלף במשחק מסוג giant. זהו קלף מסוג troop.
23. GiantObj.h - מחלקה זו מייצגת את האובייקט giant. זהו אובייקט זז של המשחק.
24. InfoPage.h - אחראית על מסך הוראות המשחק בתפריט. זהו המסך המוצג בלחיצה על לשונית "Instructions".
25. Knight.h - מחלקה זו מייצגת קלף במשחק מסוג knight. זהו קלף מסוג troop.
26. KnightObj.h - מחלקה זו מייצגת את האובייקט knight. זהו אובייקט זז של המשחק.
27. Minions.h - מחלקה זו מייצגת קלף במשחק מסוג minions. זהו קלף מסוג troop.
28. MinionsObj.h - מחלקה זו מייצגת את האובייקט minions. זהו אובייקט זז של המשחק.
29. Movable.h - זוהי מחלקת הבסיס לכל האובייקטים הזזים של המשחק. מכילה פונקציות ותכונות שמתאימות לכל האובייקטים הזזים במשחק.
30. Object.h - מחלקת הבסיס הראשית לכל סוגי האובייקטים - גם אובייקטים זזים וגם אובייקטים סטטיים.
31. ObjsProperitesConsts.h - קובץ של consts שקשורים לפרטי האובייקטים לפי רמת הקלף שלהם.
32. Pc.h - מחלקה זו אחראית על יצירת ועדכון חבילת הקלפים של המחשב במהלך המשחק.
33. PcTerritory.h - אחראית על טריטוריית המחשב במהלך המשחק. היא אובייקט סטטי של המשחק.
34. Pekka.h - מחלקה זו מייצגת קלף במשחק מסוג pekka. זהו קלף מסוג troop.
35. PekkaObj.h - מחלקה זו מייצגת את האובייקט pekka. זהו אובייקט זז של המשחק.
36. Player.h - זוהי מחלקת השחקן (המשתמש) ומכילה פונקציות ותכונות הקשורות לשחקן, כגון שלב, חיים, מטבעות, חבילת קלפים, ועוד.
37. PlayerTerritory.h - אחראית על טריטוריית השחקן (המשתמש) במהלך המשחק. היא אובייקט סטטי של המשחק.
38. Resources.h - זוהי מחלקת סינגלטון המכילה וטוענת את כל התמונות, הצלילים, והפונטים.
39. SpellCard.h - זוהי מחלקת הבסיס של קלפי ה-spell במשחק.
40. SpellObj.h - זוהי מחלקת הבסיס של האובייקטים במשחק שהם מסוג spell.
41. SpriteSheetsConsts.h - קובץ של consts שקשורים לפרטי ה-sprite sheets של כל האובייקטים שזזים במשחק.
42. Tower.h - אחראית על אובייקטי המגדלים במשחק. אלו אובייקטים סטטיים של המשחק.
43. TroopCard.h - זוהי מחלקת הבסיס של קלפי ה-troop במשחק.
44. TroopObj.h - זוהי מחלקת הבסיס של האובייקטים במשחק שהם מסוג troop.
45. Unmovable.h - זוהי מחלקת הבסיס לכל האובייקטים הסטטיים של המשחק. מכילה פונקציות ותכונות שמתאימות לכל האובייקטים הזזים במשחק.
46. Valkyrie.h - מחלקה זו מייצגת קלף במשחק מסוג valkyrie. זהו קלף מסוג troop.
47. ValkyrieObj.h - מחלקה זו מייצגת את האובייקט valkyrie. זהו אובייקט זז של המשחק.

קבצי cpp:

1. Archers.cpp
2. ArchersObj.cpp
3. ArenaBattle.cpp
4. Arrows.cpp
5. ArrowsObj.cpp
6. BattleEndScreen.cpp
7. BattlePage.cpp
8. Bullet.cpp
9. Card.cpp
10. CardsPage.cpp
11. CollisionHandling.cpp
12. Controller.cpp
13. DartGoblin.cpp
14. DartGoblinObj.cpp
15. Fireball.cpp
16. FireballObj.cpp
17. Freeze.cpp
18. FreezeObj.cpp
19. Giant.cpp
20. GiantObj.cpp
21. InfoPage.cpp
22. Knight.cpp
23. KnightObj.cpp
24. Minions.cpp
25. MinionsObj.cpp
26. Movable.cpp
27. Object.cpp
28. Pc.cpp
29. PcTerritory.cpp
30. Pekka.cpp
31. PekkaObj.cpp
32. Player.cpp
33. PlayerTerritory.cpp
34. Resources.cpp
35. SpellCard.cpp
36. Tower.cpp
37. TroopCard.cpp
38. Unmovable.cpp
39. Valkyrie.cpp
40. ValkyrieObj.cpp
41. Window.cpp



מבני נתונים עיקריים ותפקודיהם:
===========================================================
ישנן כמה מחלקות עיקריות, והן:
1. Window - מנהלת את החלון, מכילה ממבר מסוג Controller וממבר מסוג ArenaBattle.
2. ArenaBattle - מנהלת את מהלך המשחק עצמו.
3. Controller - מנהלת את תפריט המשחק. 
4. View - מחלקת הבסיס של שלושת המסכים של התפריט. יורשות ממנה מחלקות BattlePage, CardsPage, InfoPage.
5. Object - מחלקת הבסיס של כל האובייקטים במשחק. יורשות ממנו מחלקות Movable ו-Unmovable, שהן מחלקות הבסיס של האובייקטים
		הזזים והסטטיים בהתאמה.
6. Movable - מחלקת הבסיס של כל האובייקטים שזזים. יורשות ממנה המחלקות TroopObj ו-SpellObj.
7. Unmovable - מחלקת הבסיס של כל האובייקטים הסטטיים. יורשות ממנה המחלקות PcTerritory, Player Territory, Tower.
8. TroopObj - מחלקת הבסיס של כל האובייקטים שהם מסוג troop.
9. SpellObj - מחלקת הבסיס של כל האובייקטים שהם מסוג spell.
10. Card - מחלקת הבסיס של קלפי המשחק. יורשות ממנה המחלקות SpellCard ו-TroopCard.
11. TroopCard - מחלקת הבסיס של קלפי ה-Troop.
12. SpellCard - מחלקת הבסיס של קלפי ה-Spell.




אלגוריתמים הראויים לציון:
===========================================================
1. תזוזות האובייקטים:
אובייקטים מסוג troop הם אובייקטים של דמויות מסויימות, בעלות אנימצייה של הליכה ותקיפה. הם מתוכנתים להגיע לאובייקט של המחשב (אובייקט זז או מגדל) הכי קרוב אליהם,
ולתקוף אותו. אובייקט כזה יופיע על המסך עד שירדו לו כל החיים. לפני כל תזוזה של אובייקט, יש בדיקה של כל האובייקטים של היריב: חישוב מרחק בינו ולבינם לפי נוסחאת מרחק בין שתי נקודות,
כששתי הנקודות הן נקודות המרכז של כל אובייקט על הלוח, ולקיחת המרחק המינימלי מביניהם. לאחר מכן, יש בדיקה של ווקטור הכיוון בו האובייקט צריך לזוז בשביל להגיע לאובייקט של היריב שנמצא
הכי קרוב אליו. לאחר בדיקת ווקטור הכיוון, יש בדיקה של כיוון האנימציה המתאים לאובייקט לפי הכיוון בו הוא צריך ללכת.
אובייקטים מסוג spell הם מעין "מכה" של משהו כגון fireball, שנעלמים מהמסך לאחר שביצעו את הפגיעה שלהם. הפגיעה שלהם מתוכנתת להיות במקום שבו השחקן לוחץ על המסך.
2. אלגוריתמי המחשב:
קיימים שני אלגוריתמים שונים למחשב:
- בשלבים 1 ו-2 האלגוריתם של המחשב הוא בחירת קלף רנדומלי מתוך הקלפים שעומדים לרשותו באותו רגע, ואז הפעלת אלגוריתם הבודק מה המיקום הכי טוב עבור השמת אותו קלף.
- בשלבים 3 ו-4 האלגוריתם של המחשב הוא אלגוריתם חכם. הוא בודק את קלפיו לפי עדיפות של קלפים חזקים יותר שמתאימים לסיטואציה בה הוא נמצא, ובהתאם למצב השחקן. למשל, אם לשחקן קיימים
קלפי troops בטריטוריה של המחשב, הוא יבדוק אם יש לו קלף מסוג troop או spell מתאימים בשביל להגן על עצמו. בנוסף, הוא בוחן מצבים בהם כדאי לו להשתמש דווקא בקלף מסוג spell
שיעזור לו להרוס מגדל לשחקן, או דווקא בקלף חזק מסוג troop, ועוד.
3. בחירת חפיסת הקלפים של המחשב:
קלפי המחשב במשחק נבחרים באופן הבא: מקסימום הקלפים שיכולים להיות בחפיסה הוא 8. קלפי המחשב נבחרים בצורה רנדומלית מתוך כל הקלפים שהשחקן יכול להשתמש בהם, וזאת בשביל שהמשחק
יהיה פייר. למשל, אם לשחק פתוחים כרגע 9 קלפים, השחק יכול לבחור בין 6 ל-8 קלפים מתוך ה-9 שאיתם הוא מעוניין לשחק, וחפיסת המחשב תהיה 8 קלפים רנדומליים מתוך ה-9.

