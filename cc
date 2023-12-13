import React from "react";
import { useState } from "react";
import { ConfigProvider, Layout as AntdLayout } from "antd";
import "@aws-amplify/ui-react/styles.css";
import "bootstrap/dist/css/bootstrap.min.css";
import { BrowserRouter as Router, Route, Routes } from "react-router-dom";
import { Amplify } from "aws-amplify";
import {
  Authenticator,
  Heading,
  Text,
  useAuthenticator,
  useTheme,
  View,
  Button,
} from "@aws-amplify/ui-react";
import { AmplifyProvider } from "@aws-amplify/ui-react";
import Readonlypage from "./Pages/Readonlypage";
import TriggeredCallsPage from "./Pages/TriggeredCallsPage";
import ToBeReviewedPage from "./Pages/ToBeReviewedPage";
import E1 from "./Pages/E1";
import NS from "./Pages/NegativeSentiment";
import Evaluationform from "./Pages/Evaluationpage";

Amplify.configure({
  Auth: {
    mandatorySignIn: true,
    region: "ap-south-1",
    userPoolId: "ap-south-1_lNwH8hzP6",
    userPoolWebClientId: "sf6dfnopj2qrq2bs15as48lst",
  },
});

const theme = {
  name: "local-theme",
  tokens: {
    colors: {
      font: {
        // primary: { value: '#f97316' },
      },
      brand: {
        primary: {
          // 10: { value: '#FFF0DB' },
          // 20: { value: '#FFC56D' },
          // 40: { value: '#FFB649' },
          // 60: { value: '#FFA824' },
          // 80: { value: '#ED8E00' },
          // 90: { value: '#C87800' },
          // 100: { value: '#FF9900' },
        },
      },
    },
    height: "100vh",
    width: "100vw",
    // backgroundImage: <Image src={Back} alt="" />,
    backgroundSize: "100% 100%",
  },
};

const amplifyHeader = (tokens, heading) => (
  <View textAlign="center" padding={tokens.space.large}>
    {/* <Image src={Logo} alt="Header Logo" /> */}
    {heading && (
      <Heading padding={`${tokens.space.xl} 0 0 ${tokens.space.xl}`} level={3}>
        {heading}
      </Heading>
    )}
  </View>
);
const amplifyFooter = (tokens) => (
  <View textAlign="center" padding={tokens.space.large}>
    <Text>&copy; {new Date().getFullYear()} All Rights Reserved</Text>
  </View>
);

// export const DefaultImageExample = () => {
//   return (
//     <Image
//       src={Back}
//       alt="View from road to Milford Sound, New Zealand.
//   Glittering stream with old log, snowy mountain peaks
//   tower over a green field."
//     />
//   );
// };
const components = {
  Header() {
    // const { tokens } = useTheme();
    return <div />;
  },

  Footer() {
    // const { tokens } = useTheme();
    return <div />;
  },

  SignIn: {
    Header() {
      const { tokens } = useTheme();
      return amplifyHeader(tokens, "Sign in");
    },
    Footer() {
      const { toResetPassword } = useAuthenticator();
      const { tokens } = useTheme();
      return (
        <View textAlign="center">
          <Button
            fontWeight="normal"
            onClick={toResetPassword}
            size="small"
            variation="link"
          >
            Forgot your password?
          </Button>
          {amplifyFooter(tokens)}
        </View>
      );
    },
  },
  SignUp: {
    Header() {
      const { tokens } = useTheme();
      return amplifyHeader(tokens, "Create a new account");
    },
    Footer() {
      const { toSignIn } = useAuthenticator();
      const { tokens } = useTheme();
      return (
        <View textAlign="center">
          <Button
            fontWeight="normal"
            onClick={toSignIn}
            size="small"
            variation="link"
          >
            Back to Sign In
          </Button>
          {amplifyFooter(tokens)}
        </View>
      );
    },
  },
  ConfirmSignUp: {
    Header() {
      const { tokens } = useTheme();
      return amplifyHeader(tokens, "Confirm SignUp");
    },
    Footer() {
      const { tokens } = useTheme();
      return amplifyFooter(tokens);
    },
  },
  SetupTOTP: {
    Header() {
      const { tokens } = useTheme();
      return amplifyHeader(tokens, "Setup OTP");
    },
    Footer() {
      const { tokens } = useTheme();
      return amplifyFooter(tokens);
    },
  },
  ConfirmSignIn: {
    Header() {
      const { tokens } = useTheme();
      return amplifyHeader(tokens, "Confirm SignIn");
    },
    Footer() {
      const { tokens } = useTheme();
      return amplifyFooter(tokens);
    },
  },
  ResetPassword: {
    Header() {
      const { tokens } = useTheme();
      return amplifyHeader(tokens, "Reset your Password");
    },
    Footer() {
      const { tokens } = useTheme();
      return amplifyFooter(tokens);
    },
  },
  ConfirmResetPassword: {
    Header() {
      const { tokens } = useTheme();
      return amplifyHeader(tokens, "Confirm Reset Password");
    },
    Footer() {
      const { tokens } = useTheme();
      return amplifyFooter(tokens);
    },
  },
};

function Layout() {
  //Temporary logging of current API URLs
  // const TempLog = [
  //   process.env.GATSBY_SEARCH_API_URL,
  //   process.env.GATSBY_GETDOCUMENT_API_URL,
  // ];
  const [agentEVData, setAgentEVData] = useState([]);
  const [agentEVData1, setAgentEVData1] = useState([]);
  const [currentSection] = useState("currentSection");
  const [NSArray, setNSArray] = useState([]);
  const [eid, setEid] = useState("");
  //setting primary color for antd components
  const { tokens } = useTheme();
  ConfigProvider.config({
    theme: {
      primaryColor:
        (currentSection && currentSection.color) ||
        tokens.colors.teal[80].value,
    },
  });

  return (
    <>
      <AmplifyProvider theme={theme}>
        <Authenticator
          variation="modal"
          loginMechanisms={["username"]}
          hideSignUp={true}
          components={components}
        >
          {({ signOut, user }) => {
            console.log("uuu", user);
            console.log("user name", user.username);
            return (
              <>
                <View>
                  <Router>
                    {/* <Editablepage signOut={signOut}/> */}
                    {/* {user.attributes.profile === "Admin" && (
                    <Editablepage signOut={signOut} un={user.username} />
                  )}
                  {user.attributes.profile !== "Admin" && (
                    <Readonlypage signOut={signOut} un={user.username} />
                  )} */}

                    <Routes>
                      <Route
                        path="/"
                        element={
                          user.attributes.profile === "Admin" ? (
                            // <Editablepage signOut={signOut} un={user.username} setAgentEVData={setAgentEVData}/>
                            <E1
                              signOut={signOut}
                              un={user.username}
                              setAgentEVData={setAgentEVData}
                              setAgentEVData1={setAgentEVData1}
                              setNSArray={setNSArray}
                            />
                          ) : (
                            <Readonlypage
                              signOut={signOut}
                              un={user.username}
                            />
                          )
                        }
                      />
                      <Route
                        path="/triggered-calls"
                        element={
                          <TriggeredCallsPage
                            signOut={signOut}
                            un={user.username}
                            agentEVData={agentEVData}
                          />
                        }
                      />
                      <Route
                        path="/to-be-reviewed"
                        element={
                          <ToBeReviewedPage
                            signOut={signOut}
                            un={user.username}
                            agentEVData1={agentEVData1}
                            setEid={setEid}
                          />
                        }
                      />
                      <Route
                        path="/negative-sentiment"
                        element={
                          <NS
                            signOut={signOut}
                            un={user.username}
                            NSArray={NSArray}
                          />
                        }
                      />
                      <Route
                        path="/evaluation-page"
                        element={
                          <Evaluationform
                            signOut={signOut}
                            un={user.username}
                            eid={eid}
                          />
                        }
                      />
                    </Routes>
                  </Router>
                  {/* <p>hii</p> */}
                </View>
              </>
            );
          }}
        </Authenticator>
      </AmplifyProvider>
    </>
  );
}

// Layout.propTypes = {
//   children: PropTypes.node.isRequired,
// };

export default Layout;
