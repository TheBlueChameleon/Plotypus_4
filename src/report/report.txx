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
        const auto pathToOutputFile = getDerivedPath(T::getDefaultExtension());
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
            throw InvalidTypeError("Currently installed TerminalInfoProvider is of type '" + tip->getInstanceName() + "', but a '" + T::getTypeName() + "' was requested.");
        }
    }

    template<PersistableSPType T>
    void Report::addSubscriber(T& subscriber)
    {
        auto ptr = std::static_pointer_cast<Persistable>(subscriber.get());
        scriptFile.addSubscriber(ptr);
    }
}
#endif // REPORT_TXX
