#include "Deamer/External/Cpp/Tool/OopSyntaxRecognizer/Type/StructObject.h"
#include "Deamer/External/Cpp/Tool/OopSyntaxRecognizer/Type/FunctionArgument.h"
#include "Deamer/External/Cpp/Tool/OopSyntaxRecognizer/Type/FunctionObject.h"
#include "Deamer/External/Cpp/Tool/OopSyntaxRecognizer/Type/PropertyObject.h"
#include "Deamer/External/Cpp/Tool/OopSyntaxRecognizer/Type/BaseTypeObject.h"
#include <iostream>

deamer::external::cpp::tool::oopsyntaxrecognizer::StructObject::StructObject(
	const std::string& type_)
	: Type(TypeCategory::structobject, type_)
{
}

void deamer::external::cpp::tool::oopsyntaxrecognizer::StructObject::AddFunction(
	FunctionObject* functionObject, AccessModifier modifier)
{
	switch (modifier)
	{
	case AccessModifier::Public: {
		publicFunctionObjects.push_back(functionObject);
		break;
	}
	case AccessModifier::Protected: {
		protectedFunctionObjects.push_back(functionObject);
		break;
	}
	case AccessModifier::Private: {
		privateFunctionObjects.push_back(functionObject);
		break;
	}
	}
}

void deamer::external::cpp::tool::oopsyntaxrecognizer::StructObject::AddProperty(
	PropertyObject* propertyObject, AccessModifier modifier)
{
	switch (modifier)
	{
	case AccessModifier::Public: {
		publicPropertyObjects.push_back(propertyObject);
		break;
	}
	case AccessModifier::Protected: {
		protectedPropertyObjects.push_back(propertyObject);
		break;
	}
	case AccessModifier::Private: {
		privatePropertyObjects.push_back(propertyObject);
		break;
	}
	}
}

void deamer::external::cpp::tool::oopsyntaxrecognizer::StructObject::AddBaseType(
	BaseTypeObject* baseType)
{
	baseTypes.push_back(baseType);
}

void deamer::external::cpp::tool::oopsyntaxrecognizer::StructObject::Print()
{
	std::cout << "STRUCT: " << GetTypeName() << "\n";

	auto functionPrinter = [](std::vector<FunctionObject*>& functionObjects) {
		for (const auto& functionObject : functionObjects)
		{
			if (functionObject == nullptr)
			{
				throw std::logic_error("StructObject.Print: FunctionObject is nullptr.");
			}
			if (functionObject->GetReturnType() == nullptr)
			{
				throw std::logic_error(
					"StructObject.Print: FunctionObject.GetReturnType() is nullptr.");
			}

			std::cout << "\t\tFUNCTION: " << functionObject->GetName()
					  << " ReturnType: " << functionObject->GetReturnType()->GetTypeName()
					  << " Args: ";
			for (const auto& functionArgument : functionObject->GetFunctionArguments())
			{
				std::cout << functionArgument->GetName() << " "
						  << functionArgument->GetType()->GetTypeName();
				std::cout << ", ";
			}
			std::cout << "\n";
		}
	};

	auto propertyPrinter = [](std::vector<PropertyObject*>& propertyObjects) {
		for (const auto& propertyObject : propertyObjects)
		{
			if (propertyObject == nullptr)
			{
				throw std::logic_error("StructObject.Print: PropertyObject is nullptr.");
			}
			if (propertyObject->GetType() == nullptr)
			{
				throw std::logic_error("StructObject.Print: PropertyObject->GetType() is nullptr.");
			}
			std::cout << "\t\tPROPERTY: " << propertyObject->GetName()
					  << " Type: " << propertyObject->GetType()->GetTypeName() << "\n";
		}
	};

	std::cout << "\tPublic Functions: \n";
	functionPrinter(publicFunctionObjects);

	std::cout << "\tProtected Functions: \n";
	functionPrinter(protectedFunctionObjects);

	std::cout << "\tPrivate Functions: \n";
	functionPrinter(privateFunctionObjects);

	std::cout << "\tPublic Property: \n";
	propertyPrinter(publicPropertyObjects);

	std::cout << "\tProtected Property: \n";
	propertyPrinter(protectedPropertyObjects);

	std::cout << "\tPrivate Property: \n";
	propertyPrinter(privatePropertyObjects);
}

std::vector<deamer::external::cpp::tool::oopsyntaxrecognizer::FunctionObject*>
deamer::external::cpp::tool::oopsyntaxrecognizer::StructObject::GetPublicFunctions() const
{
	return publicFunctionObjects;
}

std::vector<deamer::external::cpp::tool::oopsyntaxrecognizer::FunctionObject*>
deamer::external::cpp::tool::oopsyntaxrecognizer::StructObject::GetProtectedFunctions() const
{
	return protectedFunctionObjects;
}

std::vector<deamer::external::cpp::tool::oopsyntaxrecognizer::FunctionObject*>
deamer::external::cpp::tool::oopsyntaxrecognizer::StructObject::GetPrivateFunctions() const
{
	return privateFunctionObjects;
}

std::vector<deamer::external::cpp::tool::oopsyntaxrecognizer::PropertyObject*> deamer::external::cpp::tool::
oopsyntaxrecognizer::StructObject::GetPrivateProperties() const
{
	return privatePropertyObjects;
}

std::vector<deamer::external::cpp::tool::oopsyntaxrecognizer::PropertyObject*> deamer::external::cpp::tool::
oopsyntaxrecognizer::StructObject::GetProtectedProperties() const
{
	return protectedPropertyObjects;
}

std::vector<deamer::external::cpp::tool::oopsyntaxrecognizer::PropertyObject*> deamer::external::cpp::tool::
oopsyntaxrecognizer::StructObject::GetPublicProperties() const
{
	return publicPropertyObjects;
}

std::vector<deamer::external::cpp::tool::oopsyntaxrecognizer::BaseTypeObject*>
deamer::external::cpp::tool::oopsyntaxrecognizer::StructObject::GetBaseTypes() const
{
	return baseTypes;
}
