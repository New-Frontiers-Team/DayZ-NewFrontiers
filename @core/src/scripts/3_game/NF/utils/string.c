class NF_String
{
    static string FileReadyName(string name)
	{
		name.Replace("\\", "");
		name.Replace("/", "");
		name.Replace("=", "");
		name.Replace("+", "");

		return name;
	}
}