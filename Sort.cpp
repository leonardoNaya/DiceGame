void SortDice(int dices[]) {
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (dices[j] > dices[j + 1])
            {
                int temp = dices[j];
                dices[j] = dices[j + 1];
                dices[j + 1] = temp;
            }
        }
    }
}