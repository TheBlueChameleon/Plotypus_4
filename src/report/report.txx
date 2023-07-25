#ifndef REPORT_TXX
#define REPORT_TXX

namespace Plotypus
{
    template<TerminalInfoProviderType T>
    T& Report::installTerminal()
    {
        if (tip)
        {
            delete tip;
            tip = nullptr;
        }
        tip = new T();

        setExtension(GeneratedFileType::Report, T::getDefaultExtension());
        const auto pathToOutputFile = getOutputPath(GeneratedFileType::Report);
        tip->setPath(pathToOutputFile);

    }

    template<TerminalInfoProviderType T>
    T& Report::getTerminal()
    {
        if (!tip)
        {
            throw InvalidTypeError("No TerminalInfoProvider installed");
        }

        if (auto typedTip = dynamic_cast<T*>(tip))
        {
            return *typedTip;
        }
        else
        {
            throw InvalidTypeError("Currently installed TerminalInfoProvider is of type '" + tip->getTypeName() + "', but a '" + T::getTypeName() + "' was requested." );
        }
    }
}
#endif // REPORT_TXX
