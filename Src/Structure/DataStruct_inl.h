template<typename Type>
DataMember<Type> DataStruct::GetMemberNonNull(string memberName)
{
	auto member = GetMemberNonNull(memberName);

	return static_cast<DataMember<Type>>(member);
}

DataMember<any> DataStruct::GetMemberNonNull(string memberName)
{
	auto it = m_Members.find(memberName);

	if (it == m_Members.end())
	{
		return DataMember<any>();
	}

	return it->second;
}

template<typename Type>
Type* DataStruct::Get(string memberName)
{
	auto it = m_Members.find(memberName);

	if (it == m_Members.end() || !it->second.HasValue())
	{
		return nullptr;
	}

	return reinterpret_cast<Type*>(&it->second.GetValue());
}

template<typename Type>
Type DataStruct::Get(string memberName, Type defaultMember)
{
	if (auto member = Get<Type>(memberName))
	{
		return *member;
	}

	return defaultMember;
}

template<typename Type>
void DataStruct::Add(string memberName, Type member)
{
	auto it = m_Members.find(memberName);

	if (it != m_Members.end())
	{
		it->second.SetValue(member);
	}
	else
	{
		m_Members.insert({ memberName, DataMember<Type>(memberName, member) });
	}
}