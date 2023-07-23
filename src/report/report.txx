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
    T Report::getTerminal()
    {
        if (!tip)
        {
            throw InvalidTypeError("No TerminalInfoProvider installed");
        }

        return *dynamic_cast<T*>(tip);
    }
}
#endif // REPORT_TXX
