#include "Deamer/External/Cpp/Tool/OopSyntaxRecognizer/Type/BaseTypeObject.h"

void deamer::external::cpp::tool::oopsyntaxrecognizer::BaseTypeObject::SetType(Type* type_)
{
	type = type_;
}

deamer::external::cpp::tool::oopsyntaxrecognizer::Type*
deamer::external::cpp::tool::oopsyntaxrecognizer::BaseTypeObject ::GetType() const
{
	return type;
}
