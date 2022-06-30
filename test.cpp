/*	int prisonerFailed = -1;
	int temp;

	for (int currPrison = 1; currPrison <= PRISONERS; ++currPrison)
	{
		if (prisonerFailed != -1)
		{
			break;
		}
		temp = currPrison;
		for (int j = 1; j <= tries; ++j)
		{
			if (checkBox(room, temp, currPrison))
			{
				printf("Prisoner #%d has found their number on their %dth try.\n", currPrison, j);
				printf("--------------------------------------------------------------------------------\n\n");
				break;
			}
			else if (j == tries)
			{
				printf("Prisoner #%d has failed to escape.\n", currPrison);
				printf("********************************************************************************\n\n");
				prisonerFailed = currPrison;
				break;
			}
			temp = room[temp-1];
		}
	}
	if (prisonerFailed != -1)
	{
		printf("Prisoner #%d has failed to escape.\nAll prisoners will now be terminated.\n", prisonerFailed);
	}
	else
	{
		printf("All prisoners have found their numbers, all prisoners are now free.\n");
	}

*/