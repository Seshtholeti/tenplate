import { ConnectClient, TagResourceCommand } from "@aws-sdk/client-connect"; // ES Modules import
// const { ConnectClient, TagResourceCommand } = require("@aws-sdk/client-connect"); // CommonJS import
import { ListQueuesCommand,ListUsersCommand,ListPromptsCommand,ListHoursOfOperationsCommand,ListRoutingProfilesCommand,ListPhoneNumbersCommand,ListAgentStatusesCommand } from "@aws-sdk/client-connect";

const client = new ConnectClient();
export const handler = async (event) => {
    console.log(event)
    try{
      const response= Route(event)
      return response;
    }
    catch(error){
      console.log('err',error) 
      const response= Route(event) 
      return response;
    }
};
const Queues= async (event)=>{
  const input1 = { 
      InstanceId: "bd16d991-11c8-4d1e-9900-edd5ed4a9b21",
      QueueTypes: [ // QueueTypes
        "STANDARD" 
      ],
    };
    const command1 = new ListQueuesCommand(input1);
    const response1 = await client.send(command1);
    console.log(response1);
    for(let i=0;i<response1['QueueSummaryList'].length;i++){
      console.log(response1['QueueSummaryList'][i],response1['QueueSummaryList'][i]['Arn'])
      const input = { // TagResourceRequest
        resourceArn: response1['QueueSummaryList'][i]['Arn'], 
        tags: { 
          "createdBy": "tcsAwsBU",
        },
      };
      const command = new TagResourceCommand(input);
      const response = await client.send(command);
      console.log(response); 
      // break; 
    }
    
    
}

const Users= async (event)=>{
  const input1 = { 
      InstanceId: "bd16d991-11c8-4d1e-9900-edd5ed4a9b21",
      QueueTypes: [ // QueueTypes
        "STANDARD" 
      ],
    };
    const command1 = new ListUsersCommand(input1);
    const response1 = await client.send(command1);
    console.log(response1);
    for(let i=0;i<response1['UserSummaryList'].length;i++){
      console.log(response1['UserSummaryList'][i],response1['UserSummaryList'][i]['Arn'])
      const input = { // TagResourceRequest
        resourceArn: response1['UserSummaryList'][i]['Arn'], 
        tags: { 
          "createdBy": "tcsAwsBU",
        },
      };
      const command = new TagResourceCommand(input);
      const response = await client.send(command);
      console.log(response); 
      // break; 
    }  
}


const Prompts= async (event)=>{
  const input1 = { 
      InstanceId: "bd16d991-11c8-4d1e-9900-edd5ed4a9b21",
      QueueTypes: [ // QueueTypes
        "STANDARD" 
      ],
    };
    const command1 = new ListPromptsCommand(input1);
    const response1 = await client.send(command1);
    console.log(response1);
    for(let i=0;i<response1['PromptSummaryList'].length;i++){
      console.log(response1['PromptSummaryList'][i],response1['PromptSummaryList'][i]['Arn'])
      const input = { // TagResourceRequest
        resourceArn: response1['PromptSummaryList'][i]['Arn'], 
        tags: { 
          "createdBy": "tcsAwsBU",
        },
      };
      const command = new TagResourceCommand(input);
      const response = await client.send(command);
      console.log(response); 
      // break; 
    }
    
    
}


const House= async (event)=>{
  const input1 = { 
      InstanceId: "bd16d991-11c8-4d1e-9900-edd5ed4a9b21",
      QueueTypes: [ // QueueTypes
        "STANDARD" 
      ],
    };
    const command1 = new ListHoursOfOperationsCommand(input1);
    const response1 = await client.send(command1);
    console.log(response1);
    for(let i=0;i<response1['HoursOfOperationSummaryList'].length;i++){
      console.log(response1['HoursOfOperationSummaryList'][i],response1['HoursOfOperationSummaryList'][i]['Arn'])
      const input = { // TagResourceRequest
        resourceArn: response1['HoursOfOperationSummaryList'][i]['Arn'], 
        tags: { 
          "createdBy": "tcsAwsBU",
        },
      };
      const command = new TagResourceCommand(input);
      const response = await client.send(command);
      console.log(response); 
      // break; 
    }
    
    
}



const Route= async (event)=>{
  const input1 = { 
      InstanceId: "bd16d991-11c8-4d1e-9900-edd5ed4a9b21",
      QueueTypes: [ // QueueTypes
        "STANDARD" 
      ],
    };
    const command1 = new ListRoutingProfilesCommand(input1);
    const response1 = await client.send(command1);
    console.log(response1);
    for(let i=0;i<response1['RoutingProfileSummaryList'].length;i++){
      console.log(response1['RoutingProfileSummaryList'][i],response1['RoutingProfileSummaryList'][i]['Arn'])
      const input = { // TagResourceRequest
        resourceArn: response1['RoutingProfileSummaryList'][i]['Arn'], 
        tags: { 
          "createdBy": "tcsAwsBU",
        },
      };
      const command = new TagResourceCommand(input);
      const response = await client.send(command);
      console.log(response); 
      // break; 
    }
    
    
}


const phNO= async (event)=>{
  const input1 = { 
      InstanceId: "bd16d991-11c8-4d1e-9900-edd5ed4a9b2",
      PhoneNumberTypes: [  "DID",'TOLL_FREE' ],
  PhoneNumberCountryCodes: [ // PhoneNumberCountryCodes
  "US"]
    };
    const command1 = new ListPhoneNumbersCommand(input1);
    const response1 = await client.send(command1);
    console.log(response1);
    for(let i=0;i<response1['PhoneNumberSummaryList'].length;i++){
      console.log(response1['PhoneNumberSummaryList'][i],response1['PhoneNumberSummaryList'][i]['Arn'])
      const input = { // TagResourceRequest
        resourceArn: response1['PhoneNumberSummaryList'][i]['Arn'], 
        tags: { 
          "createdBy": "tcsAwsBU",
        },
      };
      const command = new TagResourceCommand(input);
      const response = await client.send(command);
      console.log(response); 
      // break; 
    }
    
    
}

const agent= async (event)=>{
  const input1 = { 
      InstanceId: "bd16d991-11c8-4d1e-9900-edd5ed4a9b21",
      AgentStatusTypes: [ // AgentStatusTypes
    "ROUTABLE" , "CUSTOM" , "OFFLINE",
  
      ],
    };
    const command1 = new ListAgentStatusesCommand(input1);
    const response1 = await client.send(command1);
    console.log(response1);
    for(let i=0;i<response1['AgentStatusSummaryList'].length;i++){
      console.log(response1['AgentStatusSummaryList'][i],response1['AgentStatusSummaryList'][i]['Arn'])
      const input = { // TagResourceRequest
        resourceArn: response1['AgentStatusSummaryList'][i]['Arn'], 
        tags: { 
          "createdBy": "tcsAwsBU",
        },
      };
      const command = new TagResourceCommand(input);
      const response = await client.send(command);
      console.log(response); 
      // break; 
    }
    
    
}
