import { createContext, useContext, useState } from "react";


const allInfos = createContext();
const useAllInfos = () => useContext(allInfos);

const DetailInfos = ({children}) => {
    const [name, setname] = useState('');
    const [token, settoken] = useState([]);
    const [me, setme] = useState('');
    const [employees, setemployees] = useState([]);

    return (
        <allInfos.Provider
            value={{
                name,
                setname,
                token,
                settoken,
                me,
                setme,
                employees,
                setemployees,
            }}>
            {children}
        </allInfos.Provider>
    );
};

export {DetailInfos, useAllInfos};
