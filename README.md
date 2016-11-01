# Futuronic_C_Sharp_wrapper
Futuronic sdk provides integration with almost all languages but the lacking part was no integration with c# so I wrote my own wrapper in c# with limited functionalities for now.
After Building the project you will get dll named "FutronicWrapper.dll" file which you can use in c# like


        [DllImport("FutronicWrapper.dll")]
        [return: MarshalAs(UnmanagedType.I1)]
        public static extern bool OpenDevice();

