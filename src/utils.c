/*
    Function that returns the generation classification
    based on the year of birth
*/
char* generation_type(const int number)
{
    
    if(number >= 1980 && number <= 1994)
        return "Millennials";
    else if(number >= 1995 && number <= 2012)
        return "Generation Z";
        
    return "Error";

}
const int anything(const int x, const int y, const int z)
{
    if(((x > 10) && (y < 20)) || (z > 0))
        return 1;
    
    return 0;
}
