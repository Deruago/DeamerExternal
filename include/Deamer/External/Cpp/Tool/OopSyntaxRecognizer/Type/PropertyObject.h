#ifndef DEAMER_EXTERNAL_CPP_TOOL_OOPSYNTAXRECOGNIZER_TYPE_PROPERTYOBJECT_H
#define DEAMER_EXTERNAL_CPP_TOOL_OOPSYNTAXRECOGNIZER_TYPE_PROPERTYOBJECT_H

#include <string>

namespace deamer::external::cpp::tool::oopsyntaxrecognizer
{
	struct Type;

	struct PropertyObject
	{
		Type* type;
		std::string name;

		PropertyObject(Type* type_ = nullptr, const std::string& name_ = "");

		void SetName(const std::string& name_);
		void SetType(Type* type_);

		Type* GetType() const;
		std::string GetName() const;

		void Print();
	};
}

#endif // DEAMER_EXTERNAL_CPP_TOOL_OOPSYNTAXRECOGNIZER_TYPE_PROPERTYOBJECT_H
