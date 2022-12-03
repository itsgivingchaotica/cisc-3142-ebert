# **Exercise 10**
You can view workflows runs via GitHub Actions, file used was : exercise10.yaml

Alternatively you may run `make exercise10` within the exercise folder.

The output is included "results.txt" as proof of sample run.


```
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <functional>
#include <numeric>

using std::back_inserter;
using std::cerr;
using std::cout;
using std::endl;
using std::find;
using std::getline;
using std::ifstream;
using std::istringstream;
using std::ofstream;
using std::stod;
using std::stoi;
using std::string;
using std::transform;
using std::vector;

void findRunningTimes(vector<vector<string>> records, ofstream &ofs);
vector<vector<string>> makeNested(vector<vector<string>> &records, ifstream &file);
bool myComparator(const vector<string> &a, const vector<string> &b);
void listbyPopularity(vector<vector<string>> popularity, ofstream &ofs);
void printVector(const vector<int> ivec, ofstream &ofs);
void makeGenreVectors(const vector<vector<string>> &records, vector<int> &genreFilm, const string &input);
void findFirst(const string &findActor, vector<vector<string>> dvec, ofstream &ofs);

int main()
{
    ifstream file("film.csv.txt");
    // print the results to an output file
    ofstream ofs("results.txt", ofstream::out);
    vector<vector<string>> records;
    int allrunningtimes;
    // store the csv file in a nested vector
    if (file.is_open())
    {
        records = makeNested(records, file);
    }
    else
    {
        cerr << "could not read file" << endl;
    }
    ofs.flush();
    // use accumulate to sum the total length of movies
    // the algorithm is inside call to function findRunningTimes
    ofs << "a) Use accumulate to sum the total length of movies\n";
    findRunningTimes(records, ofs);
    // sort by popularity descending order
    ofs << "b) Use sort to rank movies in descending order by popularity\n";
    vector<vector<string>> popularity = records;
    sort(popularity.begin(), popularity.end(), myComparator);
    listbyPopularity(popularity, ofs);
    // use find to find the top film by the actor by popularity
    ofs << "c) Use find to find the first occurrence of an actor from the ranked movies\n";
    string actorToFind("Brando, Marlon");
    findFirst(actorToFind, popularity, ofs);
    // extract from the data two vectors: Action and Comedy
    // Use unique to find the unique years these movies were released
    ofs << "d) Extract from the data two vectors: Action and Comedy. Use unique to find the unique years these movies were released and print. Use equal to compare the two unique lists";
    vector<int> action, comedy;
    makeGenreVectors(records, action, "Action");
    makeGenreVectors(records, comedy, "Comedy");
    sort(action.begin(), action.end());
    sort(comedy.begin(), comedy.end());
    action.erase(unique(action.begin(), action.end()), action.end());
    comedy.erase(unique(comedy.begin(), comedy.end()), comedy.end());
    sort(action.begin(), action.end());
    sort(comedy.begin(), comedy.end());
    ofs << "\nYears action films were released: ";
    printVector(action, ofs);
    ofs << "\n\nYears comedy films were released: ";
    printVector(comedy, ofs);
    // use equal to compare the two unique lists
    int action_years = action.size();
    int comedy_years = comedy.size();
    if (equal((action).begin(), action.end(), comedy.begin()))
    {
        ofs << "\n\nAction and comedy have the same number of years released " << action_years << " = " << comedy_years << "\n";
    }
    else
    {
        ofs << "\n\nAction and comedy do not have the same number of years released. Action: " << action_years << ", Comedy: " << comedy_years << "\n";
    }
    ofs.flush();

    return 0;
}

void findRunningTimes(vector<vector<string>> records, ofstream &ofs)
{
    vector<int> runtimes;
    int allRunTimes;
    for (const vector<string> fields : records)
    {
        if (fields[1] != "")
        {
            int time = stoi(fields[1]);
            runtimes.push_back(time);
        }
    }
    // here using accumulate algorithm
    allRunTimes = accumulate(runtimes.begin(), runtimes.end(), 0);

    ofs << "The total running length of all movies is: " << allRunTimes << " minutes\n\n";
    ofs.flush();
}

vector<vector<string>> makeNested(vector<vector<string>> &records, ifstream &file)
{
    string line;
    getline(file, line);
    getline(file, line);
    // create the nested vector
    while (getline(file, line))
    {
        istringstream iss(line);
        vector<string> fields;
        string str;
        while (getline(iss, str, ';'))
        {
            fields.push_back(str);
        }
        records.push_back(fields);
    }
    return records;
}

bool myComparator(const vector<string> &a, const vector<string> &b)
{
    if (a[7].size() == b[7].size())
        return a[7] > b[7];
    else
        return a[7].size() > b[7].size();
}

void listbyPopularity(vector<vector<string>> popularity, ofstream &ofs)
{
    size_t counter = 0;
    ofs << "Films listed by popularity: \n";
    for (const vector<string> fields : popularity)
    {
        if (fields[7] != "")
        {
            ++counter;
            ofs << counter << ". " << fields[2] << ", " << fields[7] << "\n";
        }
    }
    ofs << "\n";
    ofs.flush();
}

void printVector(const vector<int> ivec, ofstream &ofs)
{
    for (auto i : ivec)
    {
        ofs << i << " ";
    }
    ofs.flush();
}

void makeGenreVectors(const vector<vector<string>> &records, vector<int> &genreFilm, const string &input)
{
    for (vector<string> fields : records)
    {
        string genre = fields[3];
        string year = fields[0];
        if (year != " ")
        {
            if (genre == input && year != "")
            {
                genreFilm.push_back(stoi(year));
            }
        }
    }
}

void findFirst(const string &findActor, vector<vector<string>> dvec, ofstream &ofs)
{
    vector<string>::iterator searched;
    vector<string> actors;
    for (const vector<string> fields : dvec)
    {
        string actor = fields[4];
        actors.push_back(actor);
    }
    searched = find(actors.begin(), actors.end(), findActor);

    int position = searched - actors.begin();
    vector<string> fields = dvec[0];
    ofs << "\nThe first film entry starring " << findActor << " from popularity list: \n";
    for (int j = 0; j < fields.size(); ++j)
    {
        ofs << dvec[position][j] << " ";
    }
    ofs << "\n";
    ofs.flush();
}
```

Sample Run:
```
a) Use accumulate to sum the total length of movies
The total running length of all movies is: 167446 minutes

b) Use sort to rank movies in descending order by popularity
Films listed by popularity: 
1. Best of Times, The, 88
2. Let It Ride, 88
3. New Year's Day, 88
4. Five Corners, 88
5. Fellini Satyricon, 88
6. Gonzo Presents Muppet Weird Stuff, 88
7. Great Race, The, 88
8. Blood in, Blood Out, 88
9. Guilty by Suspicion, 88
10. Time Machine, The, 88
11. Long Voyage Home, The, 88
12. They Were Expendable, 88
13. French Connection, The, 88
14. Final Notice, 88
15. Class Act, 88
16. Happy Birthday to Me, 88
17. Swedenhielms, 88
18. Dangerous Pursuit, 88
19. Creature from Black Lake, 88
20. Terror, The, 88
21. Out of Africa, 88
22. Ballad of Narayama, The, 88
23. Head Office, 88
24. Raw Nerve, 88
25. Jeremiah Johnson, 88
26. Russkies, 87
27. Destroyer, 87
28. B. A. D. Cats, 87
29. City of Joy, 87
30. X, Y & Zee, 87
31. Law & Order, 87
32. Adventures of Rex & Rinty, The, 87
33. Star Trek V: The Final Frontier, 87
34. Choice of Arms, 87
35. Jean de Florette, 87
36. John Wayne Six Pack, 87
37. Three Days of the Condor, 87
38. Superman, The Movie, 87
39. Three Strange Loves, 87
40. Libeled Lady, 86
41. Secret Policeman's Other Ball, The, 86
42. Twin Peaks, 86
43. For Your Eyes Only, 86
44. Fat Man & Little Boy, 86
45. Sacketts, The, 86
46. Viva Zapata!, 86
47. Harper, 86
48. Prince & the Pauper, The, 86
49. Golden Child, The, 86
50. Fozzie's Muppet Scrapbook, 86
51. Bliss of Mrs. Blossom, The, 86
52. Out of the Darkness, 86
53. Raven, The, 85
54. Man Who Shot Liberty Valance, The, 85
55. Magic, 85
56. As You Desire Me, 85
57. Party Girl, 85
58. Phantom of the Ritz, 85
59. Daphnis & Chloe, 85
60. Man from Montana, 85
61. Inserts, 85
62. Bury Me Not on the Lone Prairie, 85
63. That Lucky Touch, 85
64. Sanshiro Sugata, 85
65. Gunfight at the OK Corral, 84
66. King of Comedy, 84
67. Kelly's Heroes, 84
68. Big Bad John, 84
69. Marrying Man, The, 84
70. Twilight's Last Gleaming, 84
71. Love & Death, 84
72. Othello, 84
73. Surrender, 84
74. Catamount Killing, The, 84
75. Crimes of the Heart, 84
76. Dick Tracy, 84
77. She Wore a Yellow Ribbon, 84
78. Arrowsmith, 84
79. Say Goodbye Maggie Cole, 84
80. Ruthless People, 84
81. D-Day, The Sixth of June, 84
82. My Science Project, 84
83. Taps, 84
84. Legend of the Lost, 84
85. Angel & the Badman, 84
86. Ape Man, The, 83
87. Monty Python & the Holy Grail, 83
88. A Clockwork Orange, 83
89. Two Women, 83
90. Rape of the Sabines, The, 83
91. A New Leaf, 83
92. Back Door to Heaven, 83
93. Places in the Heart, 83
94. Romancing the Stone, 83
95. Overland Stage Raiders, 83
96. Woman of Affairs, 83
97. 2001: A Space Odyssey, 83
98. Swing It, Sailor!, 83
99. Getting Straight, 83
100. Doctor at Sea, 83
101. Sting, The, 83
102. El Rublo de las Dos Caras, 83
103. Dillinger, 83
104. What's New Pussycat, 83
105. Alien, 83
106. Ugetsu Monogatari, 82
107. Aliens, 82
108. Valkenvania, 82
109. Slap Shot, 82
110. Woman Next Door, The, 82
111. Butterflies Are Free, 82
112. Who's Afraid of Virginia Woolf?, 82
113. Duet for One, 82
114. Manhattan, 82
115. Fantasy Man, 82
116. Formula, The, 82
117. Burning Poles, Cecil Taylor in Performance, 82
118. Bonfire of the Vanities, The, 82
119. Rebel Without a Cause, 82
120. Meet Millie, 82
121. Nineteen Hundred, 82
122. Alice Doesn't Live Here Anymore, 82
123. Flaming Frontiers, 82
124. Queen Christina, 82
125. Deer Hunter, The, 82
126. Penitentiary III, 82
127. Heiress, The, 81
128. Swing Shift, 81
129. At Play in the Fields of the Lord, 81
130. Ryan's Daughter, 81
131. After Hours, 81
132. Matewan, 81
133. Hanover Street, 81
134. Day of the Locust, The, 81
135. Fanny and Alexander, 81
136. Tormenta Sobre Arizona, 81
137. L. A. Story, 81
138. Persona, 81
139. Grand Hotel, 81
140. Contempt, 81
141. Dersu Uzala, (The Hunter), 81
142. Play It Again, Sam, 81
143. National Lampoon's Christmas Vacation, 81
144. Reflections in a Golden Eye, 81
145. Monty Python Live at the Hollywood Bowl, 81
146. Husbands & Wives, 80
147. Lolita, 80
148. Cleopatra, 80
149. Rodeo Girl, 80
150. Hammersmith Is Out, 80
151. Cannonball Run, The, 80
152. A Question of Honor, 80
153. Check Your Guns, 80
154. Mr. Arkadin, 80
155. New Jack City, 80
156. Goon Show Movie, The, 80
157. War & Peace, 80
158. Stripped to Kill II, Live Girls, 80
159. Statue, The, 80
160. Bobo, The, 80
161. Zandalee, 80
162. Mephisto, 80
163. Scarlet Street, 80
164. Angela, 80
165. A Special Day, 80
166. Her Alibi, 80
167. 8 1/2, 80
168. It Started with a Kiss, 80
169. Silence, The, 79
170. Predator 2, 79
171. A Touch of Class, 79
172. Texas, 79
173. Joe Kidd, 79
174. Lassie Come Home, 79
175. Face at the Window, The, 79
176. Bloodsucking Pharaohs in Pittsburgh, 79
177. Rowlf's Rhapsodies with the Muppets, 79
178. Monty Python's Flying Circus, Vol 2., 79
179. Cheerleader Camp, 79
180. Russians Are Coming, the Russians Are, The, 79
181. True Stories, 79
182. Arthur, 79
183. A Married Man, 79
184. Defense of the Realm, 79
185. Siegfried, The Nibelungenlied, 79
186. Babette's Feast, 79
187. Crawling Hand, The, 79
188. Dead Zone, The, 79
189. Rocky, 78
190. Delicatessen, 78
191. Rebecca, 78
192. Wee Willie Winkie, 78
193. Mo' Better Blues, 78
194. Return of the Lash, 78
195. King of the Pecos, 78
196. Rain People, The, 78
197. Lion in Winter, THe, 78
198. Apache, 78
199. Get Out Your Handkerchiefs, 78
200. Bloodsport, 78
201. Hot to Trot, 78
202. JFK, 78
203. Circuitry Man, 78
204. A Year of the Quiet Sun, 78
205. Ferry to Hong Kong, 77
206. True Grit, 77
207. Criss Cross, 77
208. Goldfinger, 77
209. Superman IV: The Quest for Peace, 77
210. Adventures of Smilin' Jack, The, 77
211. Salvador, 77
212. Madonna, Justify My Love, 77
213. Range Feud, 77
214. Never on Tuesday, 77
215. Until They Sail, 77
216. Pink Panther, The, 77
217. Dangerous Liaisons, 77
218. El Guerrero Solitario, 77
219. Asphalt Jungle, The, 77
220. Experiment in Terror, 77
221. Blood on the Sun, 76
222. Rooster Cogburn, 76
223. Cyrano de Bergerac, 76
224. Lodger (Story of the London Fog), 76
225. Horse Soldiers, The, 76
226. A Day in October, 76
227. Salome's Last Dance, 76
228. Reds, 76
229. Posse, 76
230. Stealing Home, 76
231. Romulus & the Sabines, 76
232. Black Sunday, 76
233. Absence of Malice, 76
234. Marathon, 76
235. Keeper of the Flame, 76
236. In Country, 76
237. A Streetcar Named Desire, 75
238. Julia, 75
239. Dodesukaden, 75
240. Defending Your Life, 75
241. Roma, 75
242. RAD, 75
243. Crash & Burn, 75
244. Alone in the Dark, 75
245. Sara Dane, 75
246. Battle of Midway, The, 75
247. Burn!, 75
248. Best Defense, 75
249. Jamaica Inn, 75
250. Wild Party, The, 75
251. Man Who Haunted Himself, The, 75
252. Pretty in Pink, 75
253. Buffet Froid, 75
254. Madonna Live, The Virgin Tour, 75
255. Appointment with Death, 75
256. Unsettled Land, 75
257. Another You, 75
258. Closely Watched Trains, 75
259. Sea of Grass, The, 75
260. Randy Rides Alone, 75
261. Getting Physical, 75
262. American Autobahn, 75
263. Magic Christian, The, 75
264. Wild Times, 75
265. Meeting Venus, 74
266. Raintree County, 74
267. Best Friends, 74
268. Sabotage, 74
269. Kriemhild's Revenge, The Nibelungenlied, 74
270. Kagemusha, 74
271. Act of Piracy, 74
272. Camille, 74
273. Ciao Italia, Madonna Live from Italy, 74
274. Under Capricorn, 74
275. Hell Comes to Frogtown, 74
276. American Anthem, 74
277. Fifth Floor, The, 74
278. Fighting Kentuckian, The, 74
279. Why Me?, 74
280. Quiet Man, The, 74
281. Mystic Pizza, 74
282. Six Weeks, 73
283. Clan of the Cave Bear, The, 73
284. Reversal of Fortune, 73
285. Neath Arizona Skies, 73
286. Bang the Drum Slowly, 73
287. Boom Town, 73
288. Border Street, 73
289. Unfaithfully Yours, 73
290. Law of Desire, 73
291. Joyless Street, 73
292. Yesterday, Today & Tomorrow, 73
293. Mc Q, 73
294. Planes, Trains & Automobiles, 73
295. Frontier Horizon, 73
296. Ransom, 73
297. Single Standard, The, 73
298. Black Rain, 73
299. State of Things, The, 73
300. Gator Bait II, 73
301. Chisum, 72
302. Beat Street, 72
303. Three Godfathers, 72
304. Novice, The, 72
305. Nightbreed, 72
306. Sands of Iwo Jima, 72
307. Bandits of Dark Canyon, 72
308. Fire, Ice & Dynamite, 72
309. In a Shallow Grave, 72
310. Great McGonagall, The, 72
311. Indigo Autumn & Lilac Dream, 72
312. Count of Old Town, The, 72
313. Hearts of Darkness, A Filmmaker's Apocalypse, 72
314. Mysterious Lady, The, 72
315. Z, 72
316. Dirty Harry, 72
317. Conformist, The, 72
318. Driver's Seat, The, 72
319. Le Dernier Combat, 72
320. Hear My Song, 72
321. Flesh & the Devil, The, 72
322. Stage Fright, 72
323. Allnighter, The, 71
324. Dear Brigitte, 71
325. Programmed to Kill, 71
326. Assault, The, 71
327. A Dry White Season, 71
328. Vera Cruz, 71
329. Baja Oklahoma, 71
330. Accused, The, 71
331. Year My Voice Broke, The, 71
332. Dragonfight, 71
333. Four Horsemen of the Apocalypse, The, 71
334. Betty Blue, 71
335. Mon Oncle D'Amerique, 71
336. Prettykill, 71
337. A Chorus Line, The Movie, 71
338. Riff Raff, 71
339. Wings of Desire, 71
340. Mysterious Mr. Wong, 71
341. Killjoy, 71
342. Mogambo, 71
343. Dragonard, 71
344. Shoot Loud, Louder, I Don't Understand!, 70
345. Front, The, 70
346. Il Bidone, 70
347. To Live & Die in L. A., 70
348. Flight to Fury, 70
349. Hot Spot, 70
350. American Film Institute, Alfred Hitchcock, 70
351. Duke, The Films of John Wayne, 70
352. Caddyshack, 70
353. Sex, Lies, and Videotape, 70
354. Dr Alien, 70
355. Guys & Dolls, 70
356. Creepshow, 70
357. Hot Line, The, 70
358. Beartooth, 70
359. Bride Is Much Too Beautiful, The, 70
360. A Matter of Time, 70
361. Eyes of the Amaryllis, The, 70
362. Wild Orchids, 70
363. Presumed Innocent, 69
364. Double Edge, 69
365. Forgotten, The, 69
366. Blame It on the Bellboy, 69
367. Devils, The, 69
368. Lethal Weapon 2, 69
369. Comic Relief, 69
370. Disorderlies, 69
371. Bad Seed, The, 69
372. Heat, 69
373. Stromboli, 69
374. To Catch a Thief, 69
375. Fear, 69
376. Henry, Portrait of a Serial Killer, 69
377. Shampoo, 69
378. Johnny Tiger, 69
379. Eiger Sanction, The, 69
380. Christopher Columbus, 69
381. Menace on the Mountain, 69
382. Honkytonk Man, 69
383. Ladyhawke, 68
384. Annie Hall, 68
385. Hunting, 68
386. Bataan, 68
387. Train, The, 68
388. Polyester, 68
389. Scum, 68
390. Good, the Bad & the Ugly, The, 68
391. Law & Jake Wade, The, 68
392. Wolf at the Door, The, 68
393. Tie Me Up! Tie Me Down!, 68
394. Jewel of the Nile, The, 68
395. Octopussy, 68
396. Big Jake, 68
397. Man with Two Brains, The, 68
398. High Heels, 68
399. Hush, Hush, Sweet Charlotte, 68
400. Tucker: The Man & His Dream, 68
401. Daffy Duck's Quackbusters, 68
402. Once Around, 68
403. Glass Menagerie, The, 68
404. Trash, 68
405. Hurricane Express, The, 68
406. An Evening with Robin Williams, 68
407. Hair, 67
408. Go Tell the Spartans, 67
409. Experts, The, 67
410. Dangerous When Wet, 67
411. Lost Boys, The, 67
412. Hang 'em High, 67
413. Man Who Loved Women, The, 67
414. Diary of a Hitman, 67
415. 48 Hrs., 67
416. Spartacus, 67
417. Mata Hari, 67
418. Cactus Flower, 67
419. Tartuffe, 67
420. Jay Leno: The American Dream, 67
421. A Cry in the Dark, 67
422. On a Clear Day You Can See Forever, 67
423. Bedazzled, 67
424. Matchmaker, The, 67
425. Last Metro, The, 66
426. Men Don't Leave, 66
427. Dogfight, 66
428. Pepi Luci Bom, 66
429. White Hunter, Black Heart, 66
430. Law of the Lash, 66
431. Blackboard Jungle, The, 66
432. Number Seventeen, 66
433. Without Love, 66
434. Prize, The, 66
435. Inspiration, 66
436. Devil's Wanton, The, 66
437. Firehouse, 66
438. Dreams Lost, Dreams Found, 66
439. Crisis, 66
440. Crocodile Dundee, 66
441. Ambassador Bill, 66
442. Steel Magnolias, 66
443. Roxanne, 66
444. Baby Face, 66
445. Killer's Kiss, 66
446. Fabulous Baker Boys, The, 66
447. About Last Night, 66
448. Going Places, 66
449. On Her Majesty's Secret Service, 66
450. Women, The, 66
451. Secrets of Women, 66
452. In Harm's Way, 66
453. Life & Times of Judge Roy Bean, The, 65
454. National Enquirer, The Untold Story, 65
455. Bad Sleep Well, The, 65
456. Going Ape, 65
457. Tomorrow Is Forever, 65
458. Blue Iguana, The, 65
459. Streets of Fire, 65
460. Manxman, The, 65
461. Willy Wonka & the Chocolate Factory, 65
462. All the Right Moves, 65
463. How to Marry a Millionaire, 65
464. Loulou, 65
465. Mackintosh Man, The, 65
466. To Joy, 65
467. Devil's Disciple, The, 65
468. Back to the Future II, 65
469. Women on the Verge of a Nervous Breakdown, 65
470. Fast Times at Ridgemont High, 65
471. Howie Mandel's North American Watusi Tour, 65
472. Firefox, 64
473. Coma, 64
474. Apprenticeship of Duddy Kravitz, The, 64
475. Rio Grande, 64
476. Grease II, 64
477. Norma Rae, 64
478. Trip, The, 64
479. Susan Lennox, Her Fall & Rise, 64
480. One Woman or Two, 64
481. Brannigan, 64
482. Doc Hollywood, 64
483. Blind Man's Bluff, 64
484. Sophie's Choice, 64
485. Through a Glass Darkly, 64
486. Major League, 64
487. Sheltering Sky, The, 64
488. Ugly American, The, 63
489. Gosta Berling's Saga, 63
490. Juggernaut, 63
491. Running Mates, 63
492. Next of Kin, 63
493. Is Paris Burning?, 63
494. Dreamscape, 63
495. My Blue Heaven, 63
496. I Confess, 63
497. Madonna, Like a Virgin, 63
498. Postcards from the Edge, 63
499. Monty Python's Flying Circus, Vol 3., 63
500. Carlton-Browne of the F.O., 63
501. Boy in Blue, The, 63
502. Last Picture Show, The, 62
503. Live & Let Die, 62
504. Trip to Bountiful, The, 62
505. Virus, 62
506. Arrogant, The, 62
507. Tentacles, 62
508. Everybody's All American, 62
509. Smith!, 62
510. Goalie's Anxiety at the Penalty Kick, The, 62
511. John Cleese on How to Irritate People, 62
512. Rumor Mill, The, 62
513. Start the Revolution Without Me, 62
514. Fall of the Roman Empire, The, 62
515. Seventh Seal, The, 62
516. Donovan's Reef, 62
517. Cat Ballou, 62
518. Mama's Dirty Girls, 62
519. Last Ride of the Dalton Gang, The, 62
520. Adam's Rib, 62
521. Outlaw Country, 62
522. Ffolkes, 62
523. Whose Life Is It, Anyway?, 62
524. Audrey Rose, 62
525. Looker, 62
526. Into the Night, 62
527. Inauguration of the Pleasure Dome, 62
528. Peggy Sue Got Married, 62
529. Romance, 62
530. A Little Night Music, 61
531. Crazy People, 61
532. Tender Mercies, 61
533. A Fistful of Dollars, 61
534. Wild Frontier, The, 61
535. One Crazy Summer, 61
536. Hawk of Powder River, 61
537. Foreign Correspondent, 61
538. Fatal Attraction, 61
539. Storm, 61
540. Heartbreak Ridge, 61
541. Freaks, 61
542. Giant, 61
543. Gremlins 2: The New Batch, 61
544. Flying Tigers, 61
545. Private Benjamin, 61
546. Back in the U.S.S.R., 61
547. Death Becomes Her, 61
548. Falcon & the Snowman, The, 61
549. Only Way Home, The, 60
550. Alien: resurrection, 60
551. A Nous la Liberte, 60
552. Ten, 60
553. Crimson Pirate, The, 60
554. Funny about Love, 60
555. Secret Ceremony, 60
556. Throne of Blood, 60
557. Yojimbo, 60
558. Beguiled, The, 60
559. Cancel My Reservation, 60
560. Gary Numan - Berzerker, 60
561. Clara's Heart, 60
562. After the Fox, 60
563. Alfred Hitchcock Presents, Sorcerer's Apprentice, 60
564. Necessary Roughness, 60
565. Children's Hour, The, 60
566. A Child Is Waiting, 60
567. Ladies of the Chorus, 60
568. Doors, The, 60
569. March or Die, 59
570. Reap the Wild Wind, 59
571. After School, 59
572. Conversation, The, 59
573. Sleeper, 59
574. Sound of Music, The, 59
575. Rocky Horror Picture Show, The, 59
576. Gung Ho, 59
577. Cabaret, 59
578. Born to Ride, 59
579. Those Daring Young Men in Their Jaunty, 59
580. J-Men Forever, 59
581. Rashomon, 59
582. Alien Three, 59
583. World According to Garp, The, 59
584. Police Academy 5: Assignment Miami Beach, 59
585. Witness, 59
586. Seizure, 59
587. From the Life of the Marionettes, 58
588. Cowboys, The, 58
589. Desperate Hours, 58
590. Memoirs of an Invisible Man, 58
591. Diamond Trap, The, 58
592. John Wayne Four Pack, 58
593. Smiles of a Summer Night, 58
594. Pope of Greenwich Village, 58
595. Teen Wolf, 58
596. Prisoner of Honor., 58
597. Rich & Strange, 57
598. High Plains Drifter, 57
599. Lust for Gold, 57
600. Heartburn, 57
601. Where Eagles Dare, 57
602. Until the End of the World, 57
603. Coogan's Bluff, 57
604. A Month in the Country, 57
605. Harry & Son, 57
606. Dear America, Letters Home from Vietnam, 57
607. Gilda, 57
608. Painted Veil, The, 57
609. Lady in Question, 57
610. Cobra, 57
611. Made in Heaven, 57
612. Brink of Life, 57
613. Bronco Billy, 57
614. Voyage in Italy, 57
615. Separate but Equal, 56
616. Accidental Tourist, The, 56
617. Cannibal Women in the Avocado Jungle of Death, 56
618. Psycho, 56
619. Outsiders, The, 56
620. Courage, 56
621. Mummy's Revenge, The, 56
622. Long John Silver, 56
623. Somebody up There Likes Me, 56
624. Best of Eddie Murphy, Saturday Night Live, The, 56
625. Tightrope, 55
626. Scarlet Letter, The, 55
627. Dracula's Widow, 55
628. Secret Admirer, 55
629. Cloak & Dagger, 55
630. Chinatown, 55
631. Don Juan, 55
632. Not Without My Daughter, 55
633. Pocket Money, 55
634. Deceived, 55
635. Man of La Mancha, 55
636. Two Nights with Cleo, 54
637. White Lightning, 54
638. Another Forty-Eight Hours, 54
639. Mummy's Hand, The, 54
640. Ash Wednesday, 54
641. Green Glove, 54
642. Up the Creek, 54
643. Local Hero, 54
644. A Coeur Joie, (Head Over Heels), 54
645. Les Comperes, 54
646. Father of the Bride, 54
647. Whoopee Boys, The, 54
648. Island of Dr. Moreau, The, 54
649. Black Orchid, The, 54
650. Black Widow, 54
651. Deadly Trackers, 54
652. Rawhide, Premiere Episode, 54
653. Flame of Barbary Coast, 54
654. America's Music, Blues, 54
655. Madonna, Truth or Dare, 54
656. Between Friends, 54
657. Mosquito Coast, The, 54
658. Paris Blues, 54
659. Looking for Mr. Goodbar, 54
660. On Wings of Eagles, 53
661. Complete Dirty Harry, Magnum Force, The, 53
662. Miles from Home, 53
663. To Die Standing, 53
664. Protocol, 53
665. Rainbow, The, 53
666. A New Life, 53
667. Honeymoon in Vegas, 53
668. See You in the Morning, 53
669. High Spirits, 53
670. Allegheny Uprising, 53
671. Yol, 53
672. Brass Target, 53
673. Throwback, The, 53
674. Paris Trout, 53
675. Father's Little Dividend, 52
676. Barbarian & the Geisha, The, 52
677. Heller in Pink Tights, 52
678. Dark Command, 52
679. Mystery of the Hooded Horsemen, 52
680. Split Decisions, 52
681. Between Two Women, 52
682. Blood Feud, 52
683. Survivors, The, 52
684. Nuts, 52
685. Slightly Scarlet, 52
686. Dial M for Murder, 52
687. Silkwood, 52
688. Nobody's Fool, 52
689. Branford Marsalis, Steep, 52
690. Eddie Murphy Raw, 51
691. Beyond the Limit, 51
692. Killing, The, 51
693. We're No Angels, 51
694. Range Feud, The, 51
695. A Patch of Blue, 51
696. Flight of the Intruder, 51
697. Desk Set, 51
698. Northwest Passage, 51
699. A Shot in the Dark, 51
700. Brood, The, 51
701. Lindbergh Kidnapping Case, The, 51
702. Return of Martin Guerre, The, 51
703. Shirley Valentine, 51
704. Lovesick, 51
705. Lean on Me, 51
706. Bodycount, 51
707. Breathless, 51
708. Jack Benny Show, 51
709. Murder, 50
710. Night Tide, 50
711. Wild Bunch, The, 50
712. Tequila Sunrise, 50
713. Racing with the Moon, 50
714. Hombre, 50
715. Rhapsody in August, 50
716. Julius Caesar, 50
717. Torpedo Run, 50
718. Come Back, Little Sheba, 50
719. Final Analysis, 50
720. Amarcord, 50
721. Catch Twenty-Two, 50
722. Secret Agent, 50
723. Guess Who's Coming to Dinner, 50
724. Soggy Bottom U. S. A., 50
725. Desert Trail, The, 50
726. Surf Nazis Must Die, 50
727. Tin Men, 50
728. Big Bust Out, The, 50
729. In Too Deep, 50
730. PK. & the Kid., 49
731. Spies, 49
732. Autumn Sonata, 49
733. Sophia Loren, Her Own Story, 49
734. Down by Law, 49
735. Vagabond, 49
736. Cool Hand Luke, 49
737. Metropolis, 49
738. State of Grace, 49
739. Vampire's Kiss, 49
740. Triumph of the Spirit, 49
741. Seven Minutes in Heaven, 49
742. Quackser Fortune Has a Cousin in the Bronx, 49
743. Seems Like Old Times, 49
744. Affair in Trinidad, 49
745. Hard To Kill, 49
746. A Man & a Woman: Twenty Years Later, 49
747. A Woman's Face, 49
748. Industrial Symphony, The Dream of the Broken-Hearted, 49
749. What Comes Around, 49
750. John Wayne Collection, Red River, The, 49
751. Rookie, THe, 48
752. Misery, 48
753. Duel, 48
754. Loves of Carmen, The, 48
755. Erasure, Live Wild!, 48
756. Siesta, 48
757. Track Twenty-Nine, 48
758. Big Bands, The, 48
759. One Hundred Rifles, 48
760. Lucky Texan, 48
761. White of the Eye, 48
762. Network, 48
763. Fury, 48
764. Pat & Mike, 48
765. Buddy System, The, 48
766. A Lesson in Love, 48
767. Water, 47
768. Trick or Treat, 47
769. Chuka, 47
770. Play Misty for Me, 47
771. Young Love: Lemon Popsicle Seven, 47
772. Young Einstein, 47
773. Santee, 47
774. Attack of the Killer Tomatoes, 47
775. Paths of Glory, 47
776. Nadine, 47
777. Meridian, 47
778. Straight to Hell, 47
779. Alrededor de Medianoche, 47
780. Instant Karma, 47
781. A Man & a Woman, 46
782. Foul Play, 46
783. Sun Shines Bright, The, 46
784. Yentl, 46
785. Paint Your Wagon, 46
786. Last Hurrah, The, 46
787. What's New Pussycat?, 46
788. Fawlty Towers, Gourmet Night, Waldorf Salad & The Kipper & the Corpse, 46
789. How the West Was Won, 45
790. Ticket of Leave Man, The, 45
791. Marbella, 45
792. Full Metal Jacket, 45
793. Easy Virtue, 45
794. Macbeth, 45
795. Conan the Barbarian, 45
796. Competition, The, 45
797. Pleasure Palace, 45
798. Inside Man, The, 45
799. Spider's Stratagem, 45
800. Instant Justice, 45
801. Thirty Seconds over Tokyo, 45
802. Under the Sun of Satan, 45
803. Maurice, 45
804. Pale Rider, 45
805. All the President's Men, 45
806. Cocoon, 45
807. Back to the Beach, 45
808. Case of the Mukkinese Battle Horn, The, 45
809. House of the Rising Sun, 45
810. A View to a Kill, 44
811. Rebel Rousers, 44
812. Hot Pursuit, 44
813. Dawn Rider, The, 44
814. Spencer Tracy Legacy, The, 44
815. Hand, The, 44
816. Cimarron, 44
817. Darling, 44
818. And Now for Something Completely Different, 44
819. Encounters, 44
820. Cool World, 44
821. Joe Piscopo Video, The, 44
822. Star Wars, 44
823. Burglar, 44
824. Doin' Time on Planet Earth, 44
825. Jane Eyre, 44
826. Wings, 44
827. Pretty Woman, 43
828. West to Glory, 43
829. China Syndrome, The, 43
830. Border Feud, 43
831. She-Devil, 43
832. Power, 43
833. Blood & Guns, 43
834. Young & Innocent, 43
835. Night Train to Katmandu, THe, 43
836. Courtship of Eddie's Father, The, 43
837. Jet Pilot, 43
838. Hustler, The, 43
839. Cookie, 43
840. Legend, 42
841. Garden of the Finzi-Continis, The, 42
842. Permanent Record, 42
843. Hideaways, The, 42
844. Still of the Night, 42
845. Center of the Web, 42
846. Harvey, 42
847. Wild Strawberries, 42
848. Good Father, The, 42
849. Notorious, 42
850. Souvenir, 42
851. Adventures of Sherlock Holmes' Smarter, 42
852. World's Greatest Lover, The, 42
853. Burbs, The, 42
854. A Guy Named Joe, 42
855. Welcome Home, Roxy Carmichael, 41
856. Sicilian, The, 41
857. Desperately Seeking Susan, 41
858. Hard Choices, 41
859. Nightmare on Elm Street, Pt. 5, The Dream Child, 41
860. There's a Girl in My Soup, 41
861. Hollywood's Greatest War Movies, 41
862. Critical Condition, 41
863. Innerspace, 41
864. Mississippi Burning, 41
865. Kissing Place, The, 41
866. Kandyland, 41
867. Basic Instinct, 41
868. Kings of the Road (In the Course of Time), 41
869. Castaway, 41
870. Kitchen Toto, THe, 41
871. Beverly Hills Cop, 41
872. Man with the Golden Gun, The, 41
873. Angelic Conversation, The, 41
874. Stir Crazy, 40
875. Gold of Naples, The, 40
876. Slumber Party Massacre III, 40
877. Red Sonja, 40
878. I Love All of You (Je Vous Aime), 40
879. Persuaders, The Overture, The, 40
880. Wrong Box, The, 40
881. Shadows of the West, 40
882. Last of the Red Hot Lovers, 40
883. Once upon a Wheel, 40
884. Ninotchka, 40
885. Quick & The Dead, The, 40
886. Miami Cops, 40
887. Idiot, The, 40
888. Mother Lode, 40
889. International Velvet, 40
890. Paramount Comedy Theater: Well-Developed, 40
891. Maximum Overdrive, 40
892. Man Who Loved Cat Dancing, The, 40
893. Official Story, The, 39
894. Last of Sheila, The, 39
895. Tom Jones, 39
896. Rome Adventure, 39
897. Fellow Traveller, 39
898. Victory, 39
899. Legal Eagles, 39
900. Ms. Don Juan, 39
901. Island of Dr. Moreau, The, 39
902. Monster in the Closet, 39
903. American Graffiti, 39
904. Judgment at Nuremberg, 39
905. Hamlet, 39
906. Rope, 39
907. Maitresse, 39
908. Christopher Columbus: The Discovery, 39
909. West Side Story, 38
910. Heavens Above, 38
911. Charly, 38
912. Runaway Barge, The, 38
913. James Taylor in Concert, 38
914. Naked Night, The, 38
915. Campus Man, 38
916. White Sands, 38
917. Lady from Louisiana, 38
918. Blue City, 38
919. Bloodbath, 37
920. Fuzz, 37
921. Good Morning, Vietnam, 37
922. Hour of the Wolf, 37
923. French Lieutenant's Woman, The, 37
924. Operation Nam, 37
925. Beverly Hills Cop II, 37
926. That Naughty Girl, 37
927. Shop on Main Street, The, 37
928. Road to Hong Kong, 37
929. Unnamable II, The Statement of Randolph Carter, The, 36
930. Two Mules for Sister Sara, 36
931. Videodrome, 36
932. Woman Times Seven, 36
933. Lilies of the Field, 36
934. Wheel of Fortune, 36
935. Kids & Pesticides, 36
936. From the Hip, 36
937. Easy Rider, 36
938. Green Berets, The, 36
939. Under Cover, 36
940. Hard Ticket to Hawaii, 36
941. Germicide, 36
942. Bobby Deerfield, 36
943. Midway, 36
944. Ikiru, 36
945. Secret Policeman's Private Parts, The, 36
946. Samson & Delilah, 36
947. Mistress, 36
948. People, The, 36
949. Snow Kill, 35
950. Sunshine Boys, The, 35
951. Final Countdown, The, 35
952. Grim Reaper, The, 35
953. Too Beautiful for You, 35
954. Fighting Seabees, The, 35
955. Torn Curtain, 35
956. American Friend, The, 35
957. Matt Talbot, 35
958. Au Revoir les Enfants, 35
959. Mutiny on the Bounty, 35
960. Lawless Frontier, The, 35
961. Burnt Offerings, 35
962. Anna Karenina, 35
963. Return of October, 35
964. Seventh Cross, The, 35
965. Voyage of the Damned, 34
966. Dragon Seed, 34
967. Naked Truth, The, 34
968. Ravishing Idiot, The, 34
969. Matador, 34
970. Europa Fifty-One, 34
971. Quiller Memorandum, The, 34
972. Manhunt, The, 34
973. For a Few Dollars More, 34
974. Into the Homeland, 34
975. Steve Martin, The Funnier Side of Eastern Canada, 34
976. Yellowbeard, 34
977. Caddyshack 2, 34
978. Electric Horseman, The, 34
979. Rabid, 34
980. Pals of the Saddle, 33
981. Casablanca Express, 33
982. Elena & Her Men, 33
983. Fly, The, 33
984. Producers, The, 33
985. Court-Martial of Jackie Robinson, The, 33
986. All New Tales from the Crypt, A Trilogy, 33
987. Monty Python's the Meaning of Life, 33
988. Midnight Cowboy, 33
989. Hunchback, 33
990. After Dark My Sweet, 33
991. Scalphunters, The, 33
992. Empire Strikes Back, The, 33
993. Napoleon & Samantha, 33
994. Tempest, 33
995. One Frightened Night, 33
996. Scanners, 32
997. Walpurgis Night, 32
998. Moonraker, 32
999. Immaculate Collection, The, 32
1000. Let It Rock, 32
1001. Terms of Endearment, 32
1002. Shining, The, 32
1003. Party, The, 32
1004. Unforgiven, The, 32
1005. My Left Foot, 32
1006. Ironweed, 32
1007. Last Temptation of Christ, The, 32
1008. Passenger, The, 32
1009. Freshman, The, 32
1010. Intermezzo, 32
1011. Jubal, 32
1012. Camille Claudel, 32
1013. Rachel, Rachel, 32
1014. Shadow of a Doubt, 32
1015. Apache Woman, 32
1016. North to Alaska, 31
1017. Bells of St. Mary's, The, 31
1018. No Regrets for Our Youth, 31
1019. Secret Beyond the Door, 31
1020. Stacey!, 31
1021. Falling in Love, 31
1022. Shock 'em Dead, 31
1023. Think Dirty, 31
1024. Cyborg, 31
1025. Running Man, The, 31
1026. Little Prince, The, 31
1027. Being There, 31
1028. Night Gallery, 31
1029. Juice, 31
1030. Ranger of the Cherokee Strip, 31
1031. My Best Girl, 31
1032. Roller Blade, 31
1033. Gangbusters, 31
1034. Amazon, 30
1035. Funny Farm, 30
1036. Chattahoochee, 30
1037. Wagon Master, 30
1038. Missing, 30
1039. Winter People, 30
1040. Going Under, 30
1041. A Very Private Affair, 30
1042. Riders of Destiny, 30
1043. Bright Lights, Big City, 30
1044. Tom Thumb, 30
1045. Valley Girl, 30
1046. Funny Girl, 30
1047. John Wayne Matinee Double Feature, No. 1, 30
1048. Moon in the Gutter, The, 29
1049. Monte Walsh, 29
1050. Saint, The, 29
1051. Fiendish Plot of Dr. Fu Manchu, The, 29
1052. Police Academy 6: City under Siege, 29
1053. Circus World, 29
1054. Wait Until Spring Bandini, 29
1055. Mr. & Mrs. Bridge, 29
1056. Spiders, 29
1057. Money, The, 29
1058. Dead Ringers, 29
1059. Port of Call, 29
1060. Culpepper Cattle Company, The, 29
1061. Exorcist II, The Heretic, 29
1062. Wings of Eagles, The, 29
1063. Prom Night III, The Last Kiss, 29
1064. Ginger & Fred, 29
1065. Butch Cassidy & the Sundance Kid, 29
1066. French Lesson, 29
1067. Alamo, The, 29
1068. And God Created Woman, 29
1069. Father Murphy, A Horse from Heaven, 28
1070. Ladykillers, The, 28
1071. Doughnuts & Society, 28
1072. John Wayne Matinee Double Feature, No. 4, 28
1073. Drowning by Numbers, 28
1074. Trouble with Harry, The, 28
1075. Exorcist, The, 28
1076. Secret War of Harry Frigg, The, 28
1077. Stewardess School, 28
1078. QB VII, 28
1079. Neath the Arizona Skies, 28
1080. Cadillac Man, 28
1081. After the Shock, 28
1082. Elvira Madigan, 28
1083. Patriot Games, 28
1084. Last Tango in Paris, 28
1085. Thirty Is a Dangerous Age, Cynthia, 28
1086. Cousins, 28
1087. Sugarland Express, The, 28
1088. American Angels: Baptism of Blood, The, 28
1089. Risky Business, 28
1090. Magnum Force, 28
1091. Lone Star Trail, The, 27
1092. Lady Vanishes, 27
1093. Gardens of Stone, 27
1094. Outer Limits, The, 27
1095. Dakota, 27
1096. U S. Sub Standard., 27
1097. Paris, Texas, 27
1098. Spy Who Loved Me, The, 27
1099. Hollywood Out-Takes & Rare Footage, 27
1100. Silent Movie, 27
1101. Men, The, 27
1102. In Old California, 27
1103. Human Desire, 27
1104. Pet Sematary, 27
1105. Stark, 27
1106. Glory Stompers, The, 27
1107. Control, 27
1108. Dead Pool, The, 26
1109. Greatest Story Ever Told, The, 26
1110. Woman Who Came Back, 26
1111. One Eyed Jacks, 26
1112. Great White Death, 26
1113. Salsa: The Motion Picture, 26
1114. Powderkeg, 26
1115. Partner, 26
1116. Wild One, The, 26
1117. Freejack, 26
1118. Return Engagement, 26
1119. Only One Night, 26
1120. Ride in the Whirlwind, 26
1121. Maverick, Duel at Sundown, 26
1122. Rocket Gibraltar, 26
1123. Empire of Spiritual Ninja, 26
1124. Naked Obsession, 26
1125. Long Gray Line, The, 26
1126. Left Handed Gun, The, 26
1127. Nothing But Trouble, 25
1128. Gaslight, 25
1129. Today We Kill....Tomorrow We Die, 25
1130. Erik the Viking, 25
1131. Mademoiselle Striptease, 25
1132. Violent Men, The, 25
1133. Prizzi's Honor, 25
1134. Crack-Up, 25
1135. Wisdom, 25
1136. Hearts of Fire, 25
1137. Raging Bull, 25
1138. Boy Who Could Fly, The, 25
1139. Survival Zone, 25
1140. Street People, 25
1141. Philadelphia Story, The, 25
1142. Wrong Arm of the Law, The, 25
1143. Green Card, 25
1144. Wholly Moses!, 25
1145. Working Girl, 25
1146. Rear Window, 25
1147. Bounty, The, 25
1148. Anastasia, 24
1149. Black & White in Color, 24
1150. Savage Intruder, The, 24
1151. Monty Python's Flying Circus, Vol 1., 24
1152. Scream, 24
1153. Seven Sinners, 24
1154. Smallest Show on Earth, The, 24
1155. La Chevre, (The Goat), 24
1156. Postman Always Rings Twice, The, 24
1157. Killer Tomatoes Strike Back, 24
1158. Lonely Passion of Judith Hearne, The, 24
1159. A Certain Sacrifice, 24
1160. Quick Change, 24
1161. Fair Game, 24
1162. Strange Brew, 24
1163. Night on Earth, 24
1164. John Wayne Matinee Double Feature, No. 3, 24
1165. Bird, 24
1166. Nineteen Forty-One, 24
1167. Final Terror, The, 24
1168. Squeeze, The, 23
1169. Colors, 23
1170. Impulse, 23
1171. Barfly, 23
1172. Mannequin, 23
1173. Raising Arizona, 23
1174. A Smoky Mountain Christmas, 23
1175. Girl from Petrovka, The, 23
1176. Shakespeare Series, 23
1177. I'm All Right Jack, 23
1178. Mystery Train, 23
1179. Hell Town, 23
1180. Othello, The Lost Masterpiece, 23
1181. Class of 1984, 23
1182. I Died a Thousand Times, 23
1183. Flying Leathernecks, 23
1184. Twins, 23
1185. All about Eve, 23
1186. Sagebrush Trail, 23
1187. On Golden Pond, 23
1188. Intimate Stranger, 23
1189. Last Movie, The, 22
1190. Little Women, 22
1191. Escape from Alcatraz, 22
1192. Hollywood Mavericks, 22
1193. Altered States, 22
1194. Bloopers from Star Trek, 22
1195. John Wayne Western Greats, Rio Bravo, 22
1196. Big Trail, The, 22
1197. Alice, 22
1198. Jerk, The, 22
1199. Wildcats, 22
1200. Desiree, 22
1201. Hellfighters, 22
1202. Code Name, Emerald, 22
1203. Second Coming of Suzanne., The, 21
1204. Boys Town, 21
1205. My Life As a Dog, 21
1206. Ratings Game, The, 21
1207. They Came from Within, 21
1208. Super Duper Bloopers, 21
1209. Elizabeth Taylor Collection, The, 21
1210. Wild Geese, The, 21
1211. Rainmaker, The, 21
1212. Orphans, 21
1213. My Country Right or Wrong, 21
1214. Fighting Vigilantes, The, 21
1215. Mission, The, 20
1216. Children of a Lesser God, 20
1217. Roadhouse Sixty-Six, 20
1218. Vincent, Francois, Paul & the Others, 20
1219. Picasso Trigger, 20
1220. Wait Until Spring, Bandini, 20
1221. Puppet Master, 20
1222. King Kong Lives!, 20
1223. Endless Love, 20
1224. A Man for All Seasons, 20
1225. Steppenwolf, 20
1226. A Stolen Life, 20
1227. Like Father Like Son, 20
1228. Best of the Big Laff Off, The, 20
1229. La Dolce Vita, 20
1230. Purple Rose of Cairo, The, 20
1231. Gotta Dance, Gotta Sing, 20
1232. Masculine Feminine, 20
1233. Devil's Eye, The, 20
1234. North by Northwest, 20
1235. Shadow of the Eagle, The, 19
1236. Flashback, 19
1237. Hot Money, 19
1238. Quintet, 19
1239. Edison the Man, 19
1240. Big Fix, The, 19
1241. Skull, 19
1242. Crashing Thru, 19
1243. Dollar, 19
1244. Stand & Deliver, 19
1245. Manhunter, 19
1246. Flatliners, 19
1247. Adventures in Dinosaur City, 19
1248. Sayonara, 19
1249. Santa Claus, The Movie, 19
1250. Witches, The, 18
1251. Comedy Tonight, 18
1252. Bold Frontiersman, The, 18
1253. Modern Love, 18
1254. She's Having a Baby, 18
1255. Cries & Whispers, 18
1256. Catch a Rising Star, Tenth Anniversary, 18
1257. Women in Love., 18
1258. Old Maid, The, 18
1259. School Daze, 18
1260. Gauntlet, The, 18
1261. Inherit the Wind, 18
1262. Heroes, 17
1263. Business As Usual, 17
1264. Frantic, 17
1265. Strangers on a Train, 17
1266. So Fine, 17
1267. Riders of Pasco Basin, 17
1268. Terminator, The, 17
1269. Night Is My Future, 17
1270. Joe Versus the Volcano, 17
1271. Bloody Mama, 17
1272. Big Top Pee-wee, 17
1273. Tex Rides with the Boy Scouts, 17
1274. Crackers, 17
1275. Cocaine Cowboys, 17
1276. Hiroshima, 17
1277. Tragedy of a Ridiculous Man, 17
1278. Yakuza, The, 16
1279. Twenty Four Hours in a Woman's Life, 16
1280. Lady from Shanghai, 16
1281. Lair of the White Worm, The, 16
1282. Young Sherlock Holmes, 16
1283. Thunderbolt & Lightfoot, 16
1284. Wise Guys, 16
1285. Voulez-Vous Danser Avec Moi?, 16
1286. Ensign Pulver, 16
1287. Red River, 16
1288. Running Out of Luck, 16
1289. Hurricane Smith, 16
1290. Hideaways, 16
1291. Some Kind of Wonderful, 16
1292. Klute, 15
1293. Love Songs, 15
1294. A Woman Called Golda, 15
1295. Ninja Masters of Death, 15
1296. Le Choix des Armes, 15
1297. Appaloosa, The, 15
1298. Vampire Raiders, Ninja Queen, 15
1299. Deep Cover, 15
1300. Man Who Knew Too Much, The, 15
1301. Scrooged, 15
1302. Blood Alley, 15
1303. Good Fellas, 15
1304. Reckless, 14
1305. Dreams, 14
1306. Days of Heaven, 14
1307. Deceivers, The, 14
1308. Housesitter, 14
1309. Pelle the Conqueror, 14
1310. Target Eagle, 14
1311. Fourth Protocol, The, 14
1312. Big Jim McLain, 14
1313. June Night, 14
1314. Beauty & the Beast, 14
1315. Batman, 14
1316. Broadway Danny Rose, 14
1317. Joe Piscopo New Jersey Special, 14
1318. Almost an Angel, 14
1319. Cry of the Innocent, 13
1320. Judgement in Berlin, 13
1321. Exodus, 13
1322. Death of a Salesman, 13
1323. Golden Ninja Invasion, 13
1324. America's Music, Gospel, 13
1325. Stakeout, 13
1326. Desire under the Elms, 13
1327. Cocktail, 13
1328. Test Pilot, 13
1329. Sounds of the Seventies...& the Beat Goes, 13
1330. Bill Cosby, Live at Harrah's, 13
1331. Last Time I Saw Paris, The, 13
1332. A Big Hand for the Little Lady, 12
1333. Sweet Liberty, 12
1334. Penn & Teller Get Killed, 12
1335. Little Dorrit, 12
1336. Best of Candid Camera, The, 12
1337. Minsky's Follies, 12
1338. Exile in Concert, 12
1339. Woman of the Year, 12
1340. Ferris Bueller's Day Off, 12
1341. Cahill, United States Marshal, 12
1342. Topaz, 12
1343. Pink Cadillac, 12
1344. Lady for a Night, 12
1345. Sweet Smell of Success, 12
1346. Prisoner of Zenda, The, 12
1347. My Darling Clementine, 12
1348. Casino Royale, 11
1349. California Suite, 11
1350. Sundays & Cybele, 11
1351. Coming to America, 11
1352. Killers of Kilimanjaro, 11
1353. Summer, 11
1354. Teahouse of the August Moon, 11
1355. Bloodbrothers, 11
1356. Elephant Walk, 11
1357. Star Trek VI: The Undiscovered Country, 11
1358. Hawks, 11
1359. Monty Python's Life of Brian, 11
1360. No Mercy, 11
1361. Tom Sawyer, 11
1362. Harlem Nights, 11
1363. Shining Through, 11
1364. Madame Rosa, 11
1365. Clint Eastwood Collection, The, 11
1366. Big Town, The, 11
1367. Stanley & Livingstone, 11
1368. Young Lions, The, 10
1369. Rain Killer, The, 10
1370. El Cid, 10
1371. Kiss of the Spider Woman, 10
1372. Fire & Rain, 10
1373. Clockwise, 10
1374. If Looks Could Kill, 10
1375. Life with Father, 10
1376. Vertigo, 10
1377. Blame It on Rio, 10
1378. My Fair Lady, 10
1379. Final Alliance, The, 10
1380. Carnal Knowledge, 10
1381. Frisco Kid, The, 10
1382. Going for the Gold, 10
1383. No Small Affair, 10
1384. Day for Night, 10
1385. Mr Love., 10
1386. Searchers, The, 9
1387. Eighty-Four Charing Cross Road, 9
1388. Plenty, 9
1389. Dead-Bang, 9
1390. Back to the Future, 9
1391. Basil The Rat, 9
1392. Seven Samurai, 9
1393. Judge Priest, 9
1394. Deadline, 9
1395. Death Valley Days, Deadly Decision, 9
1396. Glitz, 9
1397. Lionheart, 9
1398. Morituri, 9
1399. Tango & Cash, 9
1400. Bandolero!, 9
1401. Naked Gun: From the Files of Police Squad!, THe, 9
1402. Boxing Babes, 9
1403. Hannie Caulder, 9
1404. Masque of the Red Death, 9
1405. Fire with Fire, 9
1406. New York, New York, 8
1407. Le Repos Du Guerrier, (Warrior's Rest), 8
1408. Born on the Fourth of July, 8
1409. Awakenings, 8
1410. Packin' It In, 8
1411. Godfather, The, 8
1412. Godfather, Pt 2., The, 8
1413. Addams Family, The, 8
1414. Thirty-Nine Steps, The, 8
1415. Bullseye!, 8
1416. Patton, 8
1417. Firemen's Ball, The, 8
1418. Highlander, 8
1419. Pioneer Marshal, 8
1420. Married to the Mob, 8
1421. Raiders of the Lost Ark, 8
1422. Indiana Jones & the Last Crusade, 8
1423. Torn Apart, 8
1424. Fisher King, The, 8
1425. Apocalypse Now, 8
1426. Hawaii, 8
1427. Boy Friend, THe, 8
1428. Torment, 8
1429. Name of the Rose, The, 8
1430. Platoon, 8
1431. Mister Roberts, 8
1432. Thunderball, 8
1433. Hunt for Red October, The, 8
1434. Terminator 2, 8
1435. Rain Man, 8
1436. Murder on the Orient Express, 8
1437. Killer Image., 8
1438. Dead Poets Society, 8
1439. Lawless Frontier, 8
1440. Tootsie, 8
1441. Silence of the Lambs, The, 8
1442. Virgin Spring, The, 8
1443. Scenes from a Mall, 8
1444. Hannah & Her Sisters, 8
1445. Witches of Eastwick, The, 8
1446. Diamonds are Forever, 8
1447. Romantic Comedy, 8
1448. E. T. The Extra-Terrestrial, 8
1449. Total Recall, 8
1450. Never Say Never Again, 8
1451. Kramer vs. Kramer, 8
1452. Top Gun, 8
1453. Hurricane, 8
1454. Dances with Wolves, 8
1455. Robin Hood: Prince of Thieves, 8
1456. Joan of Arc, 7
1457. Gandhi, 7
1458. Hurricane Express, 7
1459. Border Shootout, 7
1460. Nine & a Half Weeks, 7
1461. Blind Date, 7
1462. Outland, 7
1463. Appointment in Honduras, 7
1464. Dangerous Moves, 7
1465. Paper Chase, The, 7
1466. Sometimes a Great Notion, 7
1467. Battleground, The, 7
1468. Bad Boys, 7
1469. Great Train Robbery, The, 7
1470. Big Blue, The, 7
1471. Longest Day, The, 7
1472. A Fish Called Wanda, 7
1473. Bellboy & the Playgirls, The, 7
1474. Another Woman, 7
1475. Untouchables, The, 7
1476. Dr. No, 7
1477. Two-Way Stretch, 7
1478. Cape Fear, 7
1479. Priceless Beauty, 7
1480. Shy People, 7
1481. Red Tent, The, 7
1482. Naked Lie, 7
1483. Bedtime Story, 7
1484. New York Stories, 6
1485. Garrison Keillor's Home, 6
1486. Web of Deceit, 6
1487. Quo Vadis, 6
1488. Zardoz, 6
1489. Police Academy 3: Back in Training, 6
1490. Swing It Sailor!, 6
1491. Cuba, 6
1492. Will Rogers, Look Back in Laughter, 6
1493. Sanjuro, 6
1494. Blue Velvet, 6
1495. Killing Fields, The, 6
1496. La Femme Nikita, 6
1497. Moonstruck, 6
1498. End of Innocence, The, 6
1499. Man Who Would Be King, The, 6
1500. Wild at Heart, 6
1501. I Will, I Will...For Now, 6
1502. Crossing Delancey, 6
1503. Ghost, 6
1504. Medicine Man, 6
1505. Live at Harrah's, 6
1506. Chariots of Fire, 6
1507. Offence, The, 6
1508. Amadeus, 6
1509. House on Carroll Street, The, 6
1510. Goodbye Again, 6
1511. From Russia with Love, 6
1512. Cat Chaser, 6
1513. Driving Miss Daisy, 6
1514. What about Bob?, 6
1515. Color of Money, The, 6
1516. Subway, 6
1517. Robin & Marian, 6
1518. Passion of Anna, The, 6
1519. Empire of the Sun, 6
1520. Goodbye Girl, The, 6
1521. Sammy & Rosie Get Laid, 6
1522. Morning After, The, 6
1523. Overboard, 6
1524. Jaws, 6
1525. A Fine Madness, 6
1526. Executive Action, 6
1527. Eddie Murphy, Delirious, 6
1528. Hallelujah Trail, The, 6
1529. Wall Street, 6
1530. Vanishing Westerner, 6
1531. Un Hombre y una Mujer, 6
1532. Tommy, 5
1533. Nights in White Satin, 5
1534. McQ, 5
1535. Meteor, 5
1536. Time Lock, 5
1537. Rita, Sue & Bob Too, 5
1538. Big Shots, 5
1539. Enemies, a Love Story, 5
1540. Sword of the Valiant, 5
1541. Secret of My Success, The, 5
1542. Unbearable Lightness of Being, The, 5
1543. Time Bandits, 5
1544. Family Business, 5
1545. Casino, 5
1546. Van, The, 5
1547. Operation Pacific, 5
1548. Do the Right Thing, 5
1549. Trapper County War, 5
1550. Shooting Elizabeth, 5
1551. Comfort of Strangers, The, 5
1552. Never Let Go, 5
1553. Danton, 5
1554. Robin Williams, 4
1555. Monty Python's Flying Circus, 4
1556. Modern Times, 4
1557. Magic Town, 4
1558. Another Time, Another Place, 4
1559. Sea Chase, The, 4
1560. Crimes of Passion, 4
1561. Plain Clothes, 4
1562. Fort Apache, 4
1563. Le Charme Discret de la Bourgeoisie, 4
1564. What Price Glory?, 4
1565. Presidio, The, 4
1566. Hook, 4
1567. Tonight for Sure, 4
1568. Rumble Fish, 4
1569. Terrorists, The, 4
1570. Testament of Dr. Mabuse, The, 4
1571. Return of the Jedi, 4
1572. Out of the Blue, 4
1573. Losin' It, 4
1574. O. C. & Stiggs, 3
1575. Mr. & Mrs. Smith, 3
1576. Paper Moon, 3
1577. His Majesty O'Keefe, 3
1578. Primal Rage, 3
1579. Alan & Naomi, 3
1580. Fugitive Kind, The, 3
1581. Star Chamber, The, 3
1582. Lawless Nineties, The, 3
1583. Steve Martin Live!, 3
1584. Elephant Man, The, 3
1585. Fortune Cookie, The, 3
1586. Dark Age, 3
1587. Scenes from a Marriage, 3
1588. This Is Horror, 3
1589. John Wayne Matinee Double Feature, No. 2, 3
1590. Days of Thunder, 3
1591. John Wayne Collector's Limited Edition, 3
1592. Magician, The, 3
1593. Internal Affairs, 3
1594. Hope & Glory, 3
1595. Molly Maguires, The, 3
1596. Strictly Business, 3
1597. River's Edge, 3
1598. Two Jakes, The, 3
1599. Four American Composers, 3
1600. Johnny Dangerously, 3
1601. Adam at 6 A.M., 3
1602. Russia House, The, 3
1603. Running on Empty, 2
1604. Mary White, 2
1605. Out for Justice, 2
1606. Gor, 2
1607. Racketeer, 2
1608. Marnie, 2
1609. Curly Sue, 2
1610. Taming of the Shrew, The, 2
1611. Running Away, 2
1612. Blackmail, 2
1613. Reuben, Reuben, 2
1614. Hud, 2
1615. Winter Light, 2
1616. Wind & the Lion, The, 2
1617. Eraserhead, 2
1618. Hoosiers, 2
1619. A Walk in the Spring Rain, 2
1620. Five Easy Pieces, 2
1621. Tokyo Pop, 2
1622. So Ends Our Night, 2
1623. Treasure Seekers, The, 2
1624. Stavisky, 1
1625. Last Emperor, The, 1
1626. Cheyenne, The Iron Trail, 1
1627. Dead Calm, 1
1628. Indiscreet, 1
1629. Hells Angels on Wheels, 1
1630. Anderson Tapes, The, 1
1631. Wagonmaster, 1
1632. Law of the Golden West, 1
1633. Operation Crossbow, 1
1634. Death Valley Days, No Gun Behind His Badge, 1
1635. Ratboy, 1
1636. Holocaust, 1
1637. Blade Runner, 1
1638. A Show of Force, 1
1639. Coming Home, 1
1640. Conversation Piece, 1
1641. An Officer & a Gentleman, 1
1642. Anna Christie, 0
1643. Shalako, 0
1644. Flame & the Arrow, The, 0
1645. Nightmare at Noon, 0
1646. Tales of Tomorrow, 0
1647. Shout at the Devil, 0
1648. Employee's Entrance, 0
1649. It's My Turn, 0
1650. Airport, 0
1651. A Chorus of Disapproval, 0
1652. Hot Child in the City, 0
1653. After the Rehearsal, 0

c) Use find to find the first occurrence of an actor from the ranked movies

The first film entry starring Brando, Marlon from popularity list: 
1978 145 Superman, The Movie Action Brando, Marlon Kidder, Margot Donner, Richard 87 No brando.png

d) Extract from the data two vectors: Action and Comedy. Use unique to find the unique years these movies were released and print. Use equal to compare the two unique lists
Years action films were released: 1926 1932 1939 1940 1942 1943 1949 1950 1951 1953 1954 1956 1957 1958 1959 1960 1961 1962 1964 1966 1967 1968 1969 1970 1971 1972 1973 1974 1975 1976 1977 1978 1979 1980 1981 1982 1983 1984 1985 1986 1987 1988 1989 1990 1991 1992 1993 

Years comedy films were released: 1931 1935 1936 1937 1939 1941 1947 1948 1950 1952 1953 1954 1955 1956 1957 1958 1959 1961 1962 1963 1964 1965 1966 1967 1968 1969 1970 1971 1972 1973 1974 1975 1976 1977 1978 1979 1980 1981 1982 1983 1984 1985 1986 1987 1988 1989 1990 1991 1992 1993 

Action and comedy do not have the same number of years released. Action: 47, Comedy: 50
```

# **Redo Midterm Question**

```
#include <iostream>
#include <vector>
#include <set>

using std::cout;
using std::endl;
using std::set;
using std::string;
using std::vector;

// count the word with the most repeated occurrences in a vector
int main()
{
    set<string> aset;
    vector<string> svec = {"how", "now", "now", "now", "brown", "how", "cow"};
    int currCount, maxCount;
    string currWord, maxWord;
    for (auto it = svec.begin(); it != svec.end(); ++it)
    {
        aset.insert(*it);
    }
    for (auto a : aset)
    {
        currWord = a;
        // using count algorithm
        currCount = count(svec.begin(), svec.end(), a);
        if (currCount > maxCount)
        {
            maxCount = currCount;
            maxWord = currWord;
        }
    }
    cout << maxWord << " had the most repetitions: " << maxCount;

    return 0;
}
```

# **Additional Practice**

> Exercise 10.14: Write a lambda that takes two `ints` and returns its sum

```
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    auto add = [](int a, int b)
    {
        return a + b;
    };
    int a, b;
    cin >> a >> b;
    cout << "The sum of " << a << " + " << b << " using lambda function is : " << add(a, b) << endl;
    return 0;
}
```

> Exercise 10.30: Use stream iterators, `sort`, and `copy` to read a sequence of integers from the standard input, sort them, and then write them back to the standard output.

```
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

using std::cin;
using std::cout;
using std::istream_iterator;
using std::ostream_iterator;
using std::vector;
// Use stream iterators, `sort`, and `copy` to read a sequence of integers from the standard input, sort them, and then write them back to the standard output.
int main()
{
    istream_iterator<int> isit(cin), is_eof;
    vector<int> ivec(isit, is_eof);
    // sort the input
    sort(ivec.begin(), ivec.end());
    ostream_iterator<int> osit(cout, " ");
    // copy the output to osit
    copy(ivec.begin(), ivec.end(), osit);

    return 0;
}
```

