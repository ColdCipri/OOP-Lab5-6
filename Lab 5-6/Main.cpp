
#include "Tests.h"
#include "ui.h"
void doTests()
{
	Tests::testTutorial();
	Tests::testDynamicVector();
	Tests::testRepository();
	Tests::testController();
	Tests::testWatchList();
	Tests::testComparator();
}
int main()
{
	//doTests();
	
	Repository repo;
	Controller ctrl{ repo };
	ctrl.add("Test", "Ana", 30, 20, 3, "https://www.youtube.com/watch?v=Rub-JsjMhWY");
	ctrl.add("Test1", "Ana", 10, 50, 7, "https://www.youtube.com/watch?v=lAvIuQIhbOQ");
	ctrl.add("Test2", "Ana", 21, 42, 10, "https://www.youtube.com/watch?v=mUQZ1qmKlLY");
	ctrl.add("Test3", "Ana", 40, 30, 54, "https://www.youtube.com/watch?v=N5HgK1bTLOg");
	ctrl.add("Test4", "Dora", 23, 2, 1000, "https://www.youtube.com/watch?v=b8Luumpu_kE");
	ctrl.add("Test5", "Dora", 52, 8, 2, "https://www.youtube.com/watch?v=tT8ICXAO_-4");
	ctrl.add("Test6", "Dora", 60, 2, 1, "https://www.youtube.com/watch?v=482weZjwVHY");
	ctrl.add("Test7", "Ana", 13, 35, 3, "https://www.youtube.com/watch?v=yKATaptz3Dc");
	ctrl.add("Test8", "Ion", 25, 21, 80, "https://www.youtube.com/watch?v=_r5i5ZtUpUM");
	ctrl.add("Test9", "Ion", 35, 42, 20, "https://www.youtube.com/watch?v=bsWWHo4KDHE");
	ctrl.add("Test10", "Ion", 1, 21, 42, "https://www.youtube.com/watch?v=E_-lMZDi7Uw");
	ui u{ ctrl };


	u.run();
	return 0;
}

