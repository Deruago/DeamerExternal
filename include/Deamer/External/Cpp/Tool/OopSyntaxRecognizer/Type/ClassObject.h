#ifndef DEAMER_EXTERNAL_CPP_TOOL_OOPSYNTAXRECOGNIZER_TYPE_CLASSOBJECT_H
#define DEAMER_EXTERNAL_CPP_TOOL_OOPSYNTAXRECOGNIZER_TYPE_CLASSOBJECT_H

#include "Deamer/External/Cpp/Tool/OopSyntaxRecognizer/Type/AccessModifier.h"
#include "Deamer/External/Cpp/Tool/OopSyntaxRecognizer/Type/Type.h"
#include <vector>

namespace deamer::external::cpp::tool::oopsyntaxrecognizer
{
	struct FunctionObject;
	struct PropertyObject;
	struct BaseTypeObject;

	struct ClassObject : public Type
	{
		std::vector<FunctionObject*> publicFunctionObjects;
		std::vector<FunctionObject*> protectedFunctionObjects;
		std::vector<FunctionObject*> privateFunctionObjects;

		std::vector<PropertyObject*> publicPropertyObjects;
		std::vector<PropertyObject*> protectedPropertyObjects;
		std::vector<PropertyObject*> privatePropertyObjects;
		
		std::vector<BaseTypeObject*> baseTypes;

		ClassObject(const std::string& type_ = "");
		~ClassObject() override = default;

		// Using a flavor this can be set to any default
		void AddFunction(FunctionObject* functionObject,
						 AccessModifier modifier = AccessModifier::Private);

		void AddProperty(PropertyObject* propertyObject,
						 AccessModifier modifier = AccessModifier::Private);

		void AddBaseType(BaseTypeObject* baseType);
		
		void Print() override;

		std::vector<FunctionObject*> GetPublicFunctions() const;
		std::vector<FunctionObject*> GetProtectedFunctions() const;
		std::vector<FunctionObject*> GetPrivateFunctions() const;

		std::vector<PropertyObject*> GetPrivateProperties() const;
		std::vector<PropertyObject*> GetProtectedProperties() const;
		std::vector<PropertyObject*> GetPublicProperties() const;

		std::vector<BaseTypeObject*> GetBaseTypes() const;
	};
}

#endif // DEAMER_EXTERNAL_CPP_TOOL_OOPSYNTAXRECOGNIZER_TYPE_OOPMODEL_H
