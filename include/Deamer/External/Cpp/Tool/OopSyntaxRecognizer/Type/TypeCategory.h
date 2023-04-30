#ifndef DEAMER_EXTERNAL_CPP_TOOL_OOPSYNTAXRECOGNIZER_TYPE_TYPECATEGORY_H
#define DEAMER_EXTERNAL_CPP_TOOL_OOPSYNTAXRECOGNIZER_TYPE_TYPECATEGORY_H

namespace deamer::external::cpp::tool::oopsyntaxrecognizer
{
	enum class TypeCategory
	{
		unknown,

		standard,		 // Int, Long, Char
		classobject,	 // Class
		structobject,	 // Struct
		interfaceobject, // Interface
		enumobject,		 // Enum
	};
}

#endif // DEAMER_EXTERNAL_CPP_TOOL_OOPSYNTAXRECOGNIZER_TYPE_TYPECATEGORY_H
